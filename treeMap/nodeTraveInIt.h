#pragma once
#include"../Stack/Stack.h"
/*
二叉树的中序遍历，迭代版实现
*/
/**
*
*                  1      中序遍历：3->0->4->1->2 
                  / \
				  0  2     先遍历到左节点3，判断出该节点没有被回溯过，访问该节点
				 / \       该节点也没有右子树，且该节点也不等于它的后继节点，所以  
				 3  4      访问该后继节点并返回到其父节点1，
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
				if (!(x = x->succ())) break;  //访问完所有的节点
				backtrack = true;
			}
		}
	}
}