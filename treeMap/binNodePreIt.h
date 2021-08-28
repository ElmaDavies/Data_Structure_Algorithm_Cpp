#pragma once
/*先序遍历的迭代版本*/
#include"../Stack/Stack.h"


template<typename T>
 void static visitALongLeftBranch(BinNode<T>* x, Stack<BinNode<T>*>& s)
{
	while (x)
	{
		std::cout << x->data << "<:";
		s.push(x->rc);  
		x = x->lc;
	}
}
 /*输出树的左孩子，将右孩子入栈，当最左边路径上的没有左孩子时，
 
 接着弹出右边孩子，进行下一条路径遍历
 
 */
template<typename T>
void BinNode<T>::travelPreIt(BinNode<T>* x)
{
	Stack<BinNode<T> *> s;
	while (true)
	{
		visitALongLeftBranch(x, s);
		if (s.empty()) break;
		x = s.pop();
	}
}

