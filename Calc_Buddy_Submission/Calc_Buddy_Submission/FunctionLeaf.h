#include "stdafx.h"
#include "ExpressionTree.h"
#ifndef FUNCTION_LEAF
#define FUNCTION_LEAF

class FunctionLeaf : public ExpressionTree
{
public:
	FunctionLeaf();
	void inorder();
};

#endif	//FUNCTION_LEAF
