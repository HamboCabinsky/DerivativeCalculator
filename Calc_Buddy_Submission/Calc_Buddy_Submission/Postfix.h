#ifndef POSTFIX
#define POSTFIX

#include "stdafx.h"
#include <string>
#include <stack>
#include <sstream>

using namespace std;

//	Functions for inspecting individual characters
bool isOperator(char c);
bool isOperand(char c);
bool isOperand(string s);
bool isNum(char c);
bool isNum(string s);
bool isVar(char c);
int	 getPrecedence(char c);
//	takes an algebraic string in infix and returns it in postfix
string toPF(string infix);
//evaluate a postfix string with no variables to get a double result
double evalPF(string &pf);

#endif //POSTFIX