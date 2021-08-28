#pragma once
#include"../Stack/Stack.h"
/*
�����������������������ʵ��
*/
/**
*
*                  1      ���������3->0->4->1->2 
                  / \
				  0  2     �ȱ�������ڵ�3���жϳ��ýڵ�û�б����ݹ������ʸýڵ�
				 / \       �ýڵ�Ҳû�����������Ҹýڵ�Ҳ���������ĺ�̽ڵ㣬����  
				 3  4      ���ʸú�̽ڵ㲢���ص��丸�ڵ�1��
*
*
*/

template<typename T>
void BinNode<T>::travelInIt(BinNode<T>* x)
{
	bool backtrack = false;
	while (true)
	{
		if (!backtrack && HasLChild(*x))
		{
			x = x->lc;
		}
		else
		{
			std::cout << x->data << ":^:";
			if (HasRChild(*x))
			{
				x = x->rc;
				backtrack = false;
			}
			else
			{
				if (!(x = x->succ())) break;  //���������еĽڵ�
				backtrack = true;
			}
		}
	}
}