#pragma once

/*
*中序遍历的直接后继   1      中序遍历：3->0->4->1->2 
                  / \
				  0  2     以节点0 为例： 节点0有右孩子，直接后继就是右孩子4
				 / \       而节点4没有左孩子，直接返回  
				 3  4   对于节点4 而言，没有有右孩子，且该节点本身就是右孩子
				           返回父节点 0，父节点0不是右孩子，再返回其父节点就是1
                            				 
 */
template<typename T>
BinNode<T>* BinNode<T>::succ()
{
	BinNode<T>* s = this;
	if (rc)
	{
		s = rc;
		while (HasLChild(*s))
			s = s->lc;
	}
	else          //如从关注右节点的原因就是，中序遍历的最后一个了元素就是右孩子
	{
		while (IsRChild(*s))
			s = s->parent;
		s = s->parent;
	}

	return s;
}