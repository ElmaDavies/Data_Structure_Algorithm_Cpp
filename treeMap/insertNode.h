#pragma once
#include"binNode.h"
template <typename T>
BinNode<T>* BinNode<T>::insertAsLc(T const& e)
{
	return lc = new BinNode(e, this);
}
template<typename T>
/*��ʾ����һ���ڵ㣬�����ýڵ㸳ֵ����ǰ�ڵ�����Һ���*/
BinNode<T>* BinNode<T>::insertAsRc(T const& e)
{
	return rc = new BinNode(e, this);  //this��ʾ��ǰ�ڵ�Ϊ���ڵ�
}

