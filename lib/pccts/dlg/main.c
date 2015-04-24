/* Main function for dlg version
 *
 * SOFTWARE RIGHTS
 *
 * We reserve no LEGAL rights to the Purdue Compiler Construction Tool
 * Set (PCCTS) -- PCCTS is in the public domain.  An individual or
 * company may do whatever they wish with source code distributed with
 * PCCTS or the code generated by PCCTS, including the incorporation of
 * PCCTS, or its output, into commerical software.
 * 
 * We encourage users to develop software with PCCTS.  However, we do ask
 * that credit is given to us for developing PCCTS.  By "credit",
 * we mean that if you incorporate our source code into one of your
 * programs (commercial product, research project, or otherwise) that you
 * acknowledge this fact somewhere in the documentation, research report,
 * etc...  If you like PCCTS and have developed a nice tool with the
 * output, please mention that you developed it using PCCTS.  In
 * addition, we ask that this header remain intact in our source code.
 * As long as these guidelines are kept, we expect to continue enhancing
 * this system and expect to make other tools available as they are
 * completed.
 *
 * DLG 1.33
 * Will Cohen
 * With mods by Terence Parr; AHPCRC, University of Minnesota
 * 1989-1995
 */

#include <stdio.h>
#include "stdpccts.h"

char	program[] = "dlg";
char	version[] = "1.33";
int	numfiles = 0;
char	*file_str[2] = {NULL, NULL};
char	*mode_file = "mode.h";
char	*class_name = DEFAULT_CLASSNAME;
char	*outdir = TopDirectory;

/* Option variables */
int comp_level = 0;
int interactive = FALSE;
int case_insensitive = FALSE;
int warn_ambig = FALSE;
int gen_cpp = FALSE;

/* Option List Stuff */
void p_comp0()		{comp_level = 0;}
void p_comp1()		{comp_level = 1;}
void p_comp2()		{comp_level = 2;}
void p_stdio()		{ file_str[numfiles++] = NULL;}
void p_file(s) char *s;	{ file_str[numfiles++] = s;}
void p_cl_name(s,t)
	char *s, *t;
	{
		if ( gen_cpp ) {
			class_name = t;
		}
		else {
			warning("-cl only valid in C++ mode; -cl ignored...",0);
		}
	}
void p_mode_file(s,t) char *s,*t;{mode_file=t;}
void p_outdir(s,t) char *s,*t;{outdir=t;}
void p_ansi()		{gen_ansi = TRUE;}
void p_interactive()	{interactive = TRUE;}
void p_case_s()		{ case_insensitive = FALSE; }
void p_case_i()		{ case_insensitive = TRUE; }
void p_warn_ambig()	{ warn_ambig = TRUE; }
void p_cpp()		{ gen_cpp = TRUE; }

typedef struct {
			char *option;
			int  arg;
			void (*process)();
			char *descr;
		} Opt;

Opt options[] = {
	{ "-CC", 0, p_cpp, "Generate C++ output" },
	{ "-C0", 0, p_comp0, "No compression (default)" },
	{ "-C1", 0, p_comp1, "Compression level 1" },
	{ "-C2", 0, p_comp2, "Compression level 2" },
	{ "-ga", 0, p_ansi, "Generate ansi C"},
	{ "-Wambiguity", 0, p_warn_ambig, "Warn if expressions ambiguous"},
	{ "-m", 1, p_mode_file, "Rename lexical mode output file"},
	{ "-i", 0, p_interactive, "Build interactive scanner"},
	{ "-ci", 0, p_case_i, "Make lexical analyzer case insensitive"},
	{ "-cl", 1, p_cl_name, "Rename lexer class (DLGLexer); only used for -CC"},
	{ "-cs", 0, p_case_s, "Make lexical analyzer case sensitive (default)"},
	{ "-o",  1, p_outdir, OutputDirectoryOption},
	{ "-", 0, p_stdio, "Use standard i/o rather than file"},
	{ "*", 0, p_file, ""}, /* anything else is a file */
	{ NULL, 0, NULL }	
};

int main(argc,argv)
int argc;
char *argv[];
{
	init();
	fprintf(stderr, "%s  Version %s   1989-1995\n", &(program[0]),
		&(version[0]));
	if ( argc == 1 ) 
	{
		Opt *p = options;
		fprintf(stderr, "%s [options] f1 f2 ... fn\n",argv[0]);
		while ( *(p->option) != '*' )
		{
			fprintf(stderr, "\t%s %s\t%s\n",
							p->option,
							(p->arg)?"___":"   ",
							p->descr);
			p++;
		}
	}else{
		ProcessArgs(argc-1, &(argv[1]), options);
		if (input_stream = read_stream(file_str[0])) {
			/* don't overwrite unless input okay */
			if ( gen_cpp ) {
				output_stream = write_stream(ClassName(CPP_FILE_SUFFIX));
				if ( file_str[1]!=NULL ) {
					warning("output file implicit in C++ mode; ignored...",0);
				}
				class_stream = write_stream(ClassName(".h"));
				mode_stream = class_stream;
			}
			else {
				output_stream = write_stream(file_str[1]);
				mode_stream = write_stream(mode_file);
			}
		}
		/* make sure that error reporting routines in grammar
		   know what the file really is */
		/* make sure that reading and writing somewhere */
		if (input_stream && output_stream && mode_stream){
			ANTLR(grammar(), input_stream);
		}
		p_class_def();
	}
	if ( output_stream!=NULL ) fclose(output_stream);
	if ( !gen_cpp && mode_stream!=NULL ) fclose(mode_stream);
	if ( class_stream!=NULL ) fclose(class_stream);
	exit(PCCTS_EXIT_SUCCESS);
}


ProcessArgs(argc, argv, options)
int argc;
char **argv;
Opt *options;
{
	Opt *p;
	
	while ( argc-- > 0 )
	{
		p = options;
		while ( p->option != NULL )
		{
			if ( strcmp(p->option, "*") == 0 ||
				 strcmp(p->option, *argv) == 0 )
			{
				if ( p->arg )
				{
					(*p->process)( *argv, *(argv+1) );
					argv++;
					argc--;
				}
				else
					(*p->process)( *argv );
				break;
			}
			p++;
		}
		argv++;
	}
}

/* initialize all the variables */
init()
{
	register int i;

	special_inits();

	used_chars = empty;
	used_classes = empty;
	/* make the valid character set */
	normal_chars = empty;
	/* NOTE: MIN_CHAR is EOF */
	/* NOTE: EOF is not quite a valid char, it is special. Skip it*/
	for (i = 1; i<CHAR_RANGE; ++i){
		set_orel(i,&normal_chars);
	}
	make_nfa_model_node();
	clear_hash();
	/* NOTE: need to set this flag before the lexer starts getting */
	/* tokens */
   	func_action = FALSE;	
}

/* stuff that needs to be reset when a new automaton is being built */
new_automaton_mode()
{
	set_free(used_chars);
	clear_hash();
}
