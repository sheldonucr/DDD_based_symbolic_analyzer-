/*
 * hash.h -- define hash table entries, sizes, hash function...
 *
 * $Id: hash.h,v 1.2 95/06/15 18:06:57 parrt Exp $
 * $Revision: 1.2 $
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
 * ANTLR 1.33
 * Terence Parr
 * Parr Research Corporation
 * with Purdue University and AHPCRC, University of Minnesota
 * 1989-1995
 */

				/* H a s h  T a b l e  S t u f f */

#ifndef HashTableSize
#define HashTableSize	553
#endif
#ifndef StrTableSize
#define StrTableSize	1000000
#endif

typedef struct _entry {		/* Minimum hash table entry -- superclass */
			char *str;
			struct _entry *next;
		} Entry;

/* Hash 's' using 'size', place into h (s is modified) */
#define Hash(s,h,size)								\
	{while ( *s != '\0' ) h = (h<<1) + *s++;		\
	h %= size;}

#ifdef __STDC__
Entry	*hash_get(Entry **, char *),
		**newHashTable(void),
		*hash_add(Entry **, char *, Entry *);

void	killHashTable(Entry **);

#else
Entry *hash_get(), **newHashTable(), *hash_add();
#endif
