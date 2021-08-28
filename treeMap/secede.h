#pragma once
template<typename T>
BinTree<T>* BinTree<T>::secede(BinNode<T>* x)
{
	FromParentTo(*x) = nullptr;
	updateHeightAbove(x->parent);
	BinTree<T>* S = new BinTree<T>;
	S->_root = x;
	x->parent = nullptr;
	S->m_size = x->size();
	m_size -= S->m_size;
	return S;
}