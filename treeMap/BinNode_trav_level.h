#pragma once
#include"../queue/queue.h"

template <typename T>

void BinNode<T>::travLevel()
{
	Queue<BinNode<T>*> Q;
	Q.enqueue(this); //根节点入队
	while (!Q.empty())
	{
		BinNode<T>* x = Q.dequeue();
		std::cout<<x->data<<"-";
		if (HasLChild(*x)) Q.enqueue(x->lc);
		if (HasRChild(*x))  Q.enqueue(x->rc);
	}

}
