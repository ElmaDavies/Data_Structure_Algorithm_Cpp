#pragma once
template<typename T>
BinNode<T>* BinTree<T>::attachAsLc(BinNode<T>* x, BinTree<T>*& S)
{
	if (x->lc = S->_root)   //��s�ĸ��ڵ㸳ֵ���ڵ�x������
	{
		x->lc->parent = x;  //ȷ����S�ĸ��ڵ���Ȼ�ǽڵ�x
	}
	m_size += S->m_size; //���¸߶Ⱥ͹�ģ
	updateHeightAbove(x);
	S->_root = nullptr;  //�ͷ�ԭ��
	S->m_size = 0;
	
	S = nullptr;   
	return x;
}

template<typename T>
BinNode<T>* BinTree<T>::attachAsRc(BinNode<T>* x, BinTree<T>*& S)
{
	if (x->Rc = S->_root)   //��s�ĸ��ڵ㸳ֵ���ڵ�x������
	{
		x->Rc->parent = x;  //ȷ����S�ĸ��ڵ���Ȼ�ǽڵ�x
	}
	m_size += S->m_size; //���¸߶Ⱥ͹�ģ
	updateHeightAbove(x);
	S->_root = nullptr;  //�ͷ�����
	S->m_size = 0;
	release(S);
	S = nullptr;
	return x;
}
