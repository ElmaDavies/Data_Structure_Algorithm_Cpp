#pragma once

template <typename T> int BinTree<T>::updateHeight(BinNode<T>* x)
{
	return x->height = 1 + max(stature(x->lc), stature(x->rc)); 
	/*�������ĸ߶ȵ����亢�ӽڵ�����߶ȼ�һ*/
}

//���������������ĸ߶�
template<typename T> void BinTree<T>::updateHeightAbove(BinNode<T>* x)
{
	while (x)
	{
		updateHeight(x);
		x = x->parent;
	}
}
