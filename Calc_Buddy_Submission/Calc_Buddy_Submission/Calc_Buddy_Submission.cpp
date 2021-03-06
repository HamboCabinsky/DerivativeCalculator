#include "stdafx.h"
#include "Postfix.h"
#include <sstream>
#include <iostream>
#include "stdlib.h"
#include "ExpressionTree.h"

using namespace std;

int main()
{
	string sentinel = "yes";

	while (toupper(sentinel[0]) != 'N')
	{
		//to hold the function input by user and its postfix form
		string funct, pfFunct;

		cout << "Enter a function to take the derivative of: " << endl;
		getline(cin, funct);
		pfFunct = toPF(funct);	
		cout << endl;

		cout << "PF f(x):" << pfFunct << endl;
		cout << endl;

		ExpressionTree* root;
		root = new ExpressionTree();
		root->construct(pfFunct);

		cout << "Expression tree printed from left to right:" << endl;
		root->display();

		string exprPF = "";
		root->postfix(exprPF);
		cout << "Expression tree back to postfix: " << exprPF << endl;
		cout << endl;

		cout << "Derivative tree:" << endl;
		root->deriv();
		cout << "f'(x) = ";
		root->display();
		cout << endl;

		cout << "After simplify:" << endl;
		root->simplify();
		root->simplify();
		cout << "f'(x) = ";
		root->display();

		cout << "Deriv in postfix form: " << endl;
		string post = "";
		root->postfix(post);
		cout << post << endl;

		cout << endl;
		cout << endl;

		ExpressionTree* rtcpy;
		rtcpy = NULL;

		/*		Second derivative	turn off for exponentials ex: 5^x

		rtcpy = root->clone();

		cout << "After second derivative:" << endl;
		rtcpy->deriv();
		cout << "f''(x) = ";
		rtcpy->display();
		cout << endl;

		cout << "After simplify:" << endl;

		cout << "f''(x) = ";
		rtcpy->simplify();
		rtcpy->simplify();
		rtcpy->display();
		cout << endl;

		//*/

		cout << "Solve for x? (y/n)" << endl;
		getline(cin, sentinel);

		while (toupper(sentinel[0]) != 'N')
		{
			bool neg = false;
			double val;
			string input;
			string postfix = "";
			cout << "Enter a double value for x: " << endl;
			getline(cin, input);

			if (input[0] == '-')
			{
				neg = true;
				input.erase(0, 1);
			}

			val = stod(input);
			if (neg == true)	val *= -1;

			root->postfix(postfix);

			string pfFunct_ = "";
			pfFunct_ += pfFunct;

			while (pfFunct_.find('x') != string::npos)	if ((pfFunct_.find('x') != string::npos)) pfFunct_.replace(pfFunct_.find('x'), 1, to_string(val));

			//	Replaces all 'x's in postfix string with string representation of entered number
			while (postfix.find('x') != string::npos)	if ((postfix.find('x') != string::npos)) postfix.replace(postfix.find('x'), 1, to_string(val));

			cout << "Results: " << endl;
			cout << "f(" << val << ") = " << evalPF(pfFunct_) << endl;
			cout << "f'(" << val << ") = " << evalPF(postfix) << endl;
			cout << endl;
			cout << "Solve for x again? (y/n)" << endl;
			getline(cin, sentinel);
		}

		root->destroy();
		if (rtcpy != NULL)	rtcpy->destroy();


		cout << "Would you like to derive another function? (y/n)" << endl;
		getline(cin, sentinel);
		system("CLS");
	}


	return 0;
}

//	Built in part using https://www.cs.csustan.edu/~john/Classes/Previous_Semesters/CS3100_DataStructures/2003_04_Fall/Asg04/DiffAsg.html
//			as a guide

//	Used https://www.derivative-calculator.net/ to aid in checking answers