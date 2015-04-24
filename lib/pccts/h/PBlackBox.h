#ifndef PBLACKBOX_H
#define PBLACKBOX_H

/*
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
 * ANTLR 1.33
 * Terence Parr
 * Parr Research Corporation
 * with Purdue University and AHPCRC, University of Minnesota
 * 1989-1995
 */

#include <iostream.h>

template<class Lexer, class Parser, class Token>
class ParserBlackBox {
protected:
	DLGFileInput *in;
	Lexer *scan;
	_ANTLRTokenPtr tok;
	ANTLRTokenBuffer *pipe;
	Parser *_parser;
	FILE *file;
public:
	
	ParserBlackBox(FILE *f)
		{
			file = f;
			in = new DLGFileInput(f);
			scan = new Lexer(in);
			pipe = new ANTLRTokenBuffer(scan);
			tok = new Token;
			scan->setToken(tok);
			_parser = new Parser(pipe);
			_parser->init();
		}
	ParserBlackBox(char *fname)
		{
			FILE *f = fopen(fname, "r");
			if ( f==NULL ) {cerr << "cannot open " << fname << "\n"; return;}
			else {
				file = f;
				in = new DLGFileInput(f);
				scan = new Lexer(in);
				pipe = new ANTLRTokenBuffer(scan);
				tok = new Token;
				scan->setToken(tok);
				_parser = new Parser(pipe);
				_parser->init();
			}
		}
	~ParserBlackBox()
		{
			delete in; delete scan; delete pipe; delete _parser; delete tok;
			fclose(file);
		}

	Parser *parser()	{ return _parser; }
};

#endif
