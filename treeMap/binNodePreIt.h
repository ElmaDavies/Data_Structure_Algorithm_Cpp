#pragma once
/*��������ĵ����汾*/
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
 /*����������ӣ����Һ�����ջ���������·���ϵ�û������ʱ��
 
 ���ŵ����ұߺ��ӣ�������һ��·������
 
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

