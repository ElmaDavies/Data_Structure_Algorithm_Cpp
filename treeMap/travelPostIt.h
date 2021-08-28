#pragma once
#include"../Stack/Stack.h"
/*
从顶向下，依次入栈当前元素

后序遍历：3->4->0->2->1
                   1       
				  / \      按照后序遍历的顺序，优先入栈右节点，
				  0  2     从根节点开始，入栈顺序时，1->2->0->4->3
				 / \       因为节点2 没有叶节点，所以转到节点0，重新开始
				 3  4      
*/
template<typename T>
 void gotoHLVFL(Stack<BinNode<T>*>& S)
{
	while (BinNode<T>* x = S.top())
	{
		if (HasLChild(*x))  //优先入栈右孩子
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
	S.pop(); //弹出栈顶的空节点
}


template<typename T>
void BinNode<T>::travelPostIt(BinNode<T>* x)
{
	Stack<BinNode<T>*> S;
	if (x) S.push(x); //根节点入栈
	while (!S.empty())
	{
		if (S.top() != x->parent)    //若栈顶非当前节点之父节点
		{
			gotoHLVFL(S);
		}
		x = S.pop();
		std::cout << x->data << "=>:";
	}
}