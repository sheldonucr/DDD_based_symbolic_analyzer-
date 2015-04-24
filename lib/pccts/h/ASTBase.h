/* Abstract syntax tree
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

#ifndef ASTBase_H
#define ASTBase_H

#include <stdio.h>
#include <stdlib.h>
#include "PCCTSAST.h"

/*
 * Notes:
 *
 * To specify a copy constructor, subclass one of these classes and
 * give the copy constructor.  To use dup(), you must define shallowCopy().
 * shallowCopy() can use either a copy constructor or just copy the node
 * itself.
 */

class ASTBase : public PCCTS_AST {
protected:
	ASTBase *_right, *_down;

public:
	PCCTS_AST *right()	{ return _right; }	// define the SORCERER interface
	PCCTS_AST *down()	{ return _down; }
	void setRight(PCCTS_AST *t)	{ _right = (ASTBase *)t; }
	void setDown(PCCTS_AST *t)	{ _down = (ASTBase *)t; }

	ASTBase() { _right = _down = NULL; }
	virtual ~ASTBase() { ; }
	virtual ASTBase *dup();
	void destroy();
	void preorder();
	static ASTBase *tmake(ASTBase *, ...);
	static void link(ASTBase **, ASTBase **, ASTBase **);
	void subchild(ASTBase **, ASTBase **, ASTBase **);
	void subroot(ASTBase **, ASTBase **, ASTBase **);
	virtual void preorder_action() { ; }
	virtual void preorder_before_action() { printf(" ("); }
	virtual void preorder_after_action() { printf(" )"); }
};

class ASTDoublyLinkedBase : public ASTBase {
protected:
	ASTDoublyLinkedBase *_left, *_up;

public:
	void double_link(ASTBase *left, ASTBase *up);
	virtual ASTBase *dup();
	PCCTS_AST *left() { return _left; }
	PCCTS_AST *up() { return _up; }
};

class AST;	// announce that this class will be coming along shortly
#endif
