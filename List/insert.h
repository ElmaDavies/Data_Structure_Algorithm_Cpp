#pragma once
#include"listnode.h"
template <typename T>
/*
 *      *<------------>*
 *       --  ^()^   --
 *         -- _=_ --
 *             *
 *
 *    ˫����������Ҫ������������
 */
listnode<T>* listnode<T>::insertAspred(T const& e)
{
	//����һ���½ڵ㣬�ýڵ�ĺ�̽ڵ��ǵ�ǰ�ڵ�
	listnode<T>* newNode = new listnode(e, pred, this);
	pred->succ = newNode;
	pred = newNode;
	return newNode;
}

template <typename T>
listnode<T>* listnode<T>::insertAssucc(T const& e)
{
	listnode <T>* newNode = new listnode(e, this, succ);
	succ->pred = newNode; //������������
	succ = newNode;			//������������
	return newNode;


}

