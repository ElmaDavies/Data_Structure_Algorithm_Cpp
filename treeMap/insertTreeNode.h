#pragma once
template <typename T>
BinNode<T>* BinTree<T>::insertAsRoot(T const& e)
{
	m_size = 1;
	return _root = new BinNode<T>(e);
}

template <typename T>
BinNode<T>* BinTree<T>::insertAsLc(BinNode<T>* x, T const& e)
{
	m_size++;
	x->insertAsLc(e);
	updateHeightAbove(x);
	return x->lc;
}


template<typename T>
BinNode<T>* BinTree<T>::insertAsRc(BinNode<T>* x, T const& e)
{
	m_size++;
	x->insertAsRc(e);
	updateHeightAbove(x);
	return x->rc;
}