#include<iostream>
#include"stack_practice.h"
using namespace std;

int main()
{
	
	Stack<char> S;
	
    convert(S, 10, 16);
	S.traverse();
	Stack<char> S1;
	char exp[] =  "())";
	cout<< brackets_match(exp,0,2)<<endl;
	//char *sp3;
	char str8[] = "(1+2)*3*2+6";
    RPN(str8);
	
	cout<<compute(returnStr, length)<<endl;
	
	cout << endl;
	//cout << sp2.empty() << endl;
	Stack<Queen> qe;

	//placeQueens(4);
	system("pause");
	return 0;
}