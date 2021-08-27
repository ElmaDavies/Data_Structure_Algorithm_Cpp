#pragma once
#include"listnode.h"
template <typename T>
/*
 *      *<------------>*
 *       --  ^()^   --
 *         -- _=_ --
 *             *
 *
 *    双向链表，所以要考虑两个方向
 */
listnode<T>* listnode<T>::insertAspred(T const& e)
{
	//创建一个新节点，该节点的后继节点是当前节点
	listnode<T>* newNode = new listnode(e, pred, this);
	pred->succ = newNode;
	pred = newNode;
	return newNode;
}

template <typename T>
listnode<T>* listnode<T>::insertAssucc(T const& e)
{
	listnode <T>* newNode = new listnode(e, this, succ);
	succ->pred = newNode; //设置逆向连接
	succ = newNode;			//设置逆向连接
	return newNode;


}

