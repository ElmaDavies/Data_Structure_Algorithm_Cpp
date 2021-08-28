#pragma once
template<typename T>
int BinTree<T>::remove(BinNode<T>* x)
{
	FromParentTo(*x) = nullptr;
	updateHeightAbove(x->parent); //�������ȸ߶�
	int n = removeAt(x);
	m_size -= n;
	return n;
	
}

template<typename T>
 static int removeAt(BinNode<T>* x)
{
	if (!x) return 0;
	int n = 1 + removeAt(x->lc) + removeAt(x->rc);  //�ݹ�ɾ���ڵ�
	
	return n;
}