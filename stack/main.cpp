#include"Stack.h"
#include"Stack_list.h"
#include<iostream>
using namespace std;

/**
栈的结构:
*           6
*           |
*           5
*           |
*           4
*           |
*           3
*
**/

int main()
{
	Stack<int> stack;
	stack.push(3);    
	stack.push(4);
	stack.push(5);
	stack.push(5);
	stack.traverse();
	stack.pop();
	cout << endl<<"---------" << endl;
	cout << endl << "栈顶元素：" << stack.top() << endl;
	stack.traverse();
	cout << stack.empty() << endl;
	cout << stack.findElement(5) << endl;
	system("color a");
	system("pause");
	
	return 0;
}