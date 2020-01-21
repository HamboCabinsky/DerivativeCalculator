#ifndef EXPRESSION_TREE
#define EXPRESSION_TREE

#include "stdafx.h"
#include "Postfix.h"
#include <string>
#include <stack>
#include <iostream>
#include <cmath>

class ExpressionTree
{
protected:
	string value;
	ExpressionTree *lhs, *rhs;
public:
	//constructor
	ExpressionTree();
	//clones the ExpressionTree recursively and returns a pointer to the clone
	ExpressionTree * clone();
	//constructs an ExpressionTree from a given string formatted in postfix
	void construct(string PF);
	//recursively destroys tree and all its children
	void destroy();
	//recursively displays tree inorder showing order of operations with parantheses
	virtual void inorder();
	//recursively tranforms the ExpressionTree into an ExpressionTree representing its derivative 
	void deriv();
	//performs routine simplifications on the Expression tree where possible
	void simplify();
	//takes a given string variable by reference and appends the ExpressionTree in postfix notation to it recursively
	void postfix(string& pf);
	//displays an ExpressionTree without outer parans and ends line
	void display();

};

#endif // EXPRESSION_TREE
