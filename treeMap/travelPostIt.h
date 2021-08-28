#pragma once
#include"../Stack/Stack.h"
/*
�Ӷ����£�������ջ��ǰԪ��

���������3->4->0->2->1
                   1       
				  / \      ���պ��������˳��������ջ�ҽڵ㣬
				  0  2     �Ӹ��ڵ㿪ʼ����ջ˳��ʱ��1->2->0->4->3
				 / \       ��Ϊ�ڵ�2 û��Ҷ�ڵ㣬����ת���ڵ�0�����¿�ʼ
				 3  4      
*/
template<typename T>
 void gotoHLVFL(Stack<BinNode<T>*>& S)
{
	while (BinNode<T>* x = S.top())
	{
		if (HasLChild(*x))  //������ջ�Һ���
		{
			if (HasRChild(*x))    
			{
				S.push(x->rc);
			}
			S.push(x->lc);
		}
		else   
		{
			S.push(x->rc);  
		}
		
	}
	S.pop(); //����ջ���Ŀսڵ�
}


template<typename T>
void BinNode<T>::travelPostIt(BinNode<T>* x)
{
	Stack<BinNode<T>*> S;
	if (x) S.push(x); //���ڵ���ջ
	while (!S.empty())
	{
		if (S.top() != x->parent)    //��ջ���ǵ�ǰ�ڵ�֮���ڵ�
		{
			gotoHLVFL(S);
		}
		x = S.pop();
		std::cout << x->data << "=>:";
	}
}