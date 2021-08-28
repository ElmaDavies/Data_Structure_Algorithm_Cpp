#pragma once
#include"binNode.h"
template <typename T>
BinNode<T>* BinNode<T>::insertAsLc(T const& e)
{
	return lc = new BinNode(e, this);
}
template<typename T>
/*表示生成一个节点，并将该节点赋值给当前节点的左右孩子*/
BinNode<T>* BinNode<T>::insertAsRc(T const& e)
{
	return rc = new BinNode(e, this);  //this表示当前节点为父节点
}

