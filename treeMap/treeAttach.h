#pragma once
template<typename T>
BinNode<T>* BinTree<T>::attachAsLc(BinNode<T>* x, BinTree<T>*& S)
{
	if (x->lc = S->_root)   //将s的根节点赋值给节点x的左孩子
	{
		x->lc->parent = x;  //确保将S的父节点仍然是节点x
	}
	m_size += S->m_size; //更新高度和规模
	updateHeightAbove(x);
	S->_root = nullptr;  //释放原树
	S->m_size = 0;
	
	S = nullptr;   
	return x;
}

template<typename T>
BinNode<T>* BinTree<T>::attachAsRc(BinNode<T>* x, BinTree<T>*& S)
{
	if (x->Rc = S->_root)   //将s的根节点赋值给节点x的左孩子
	{
		x->Rc->parent = x;  //确保将S的父节点仍然是节点x
	}
	m_size += S->m_size; //更新高度和规模
	updateHeightAbove(x);
	S->_root = nullptr;  //释放子树
	S->m_size = 0;
	release(S);
	S = nullptr;
	return x;
}
