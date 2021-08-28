#pragma once

template <typename T> int BinTree<T>::updateHeight(BinNode<T>* x)
{
	return x->height = 1 + max(stature(x->lc), stature(x->rc)); 
	/*二叉树的高度等于其孩子节点的最大高度加一*/
}

//更新整个二叉树的高度
template<typename T> void BinTree<T>::updateHeightAbove(BinNode<T>* x)
{
	while (x)
	{
		updateHeight(x);
		x = x->parent;
	}
}
