#pragma once

/*
*���������ֱ�Ӻ��   1      ���������3->0->4->1->2 
                  / \
				  0  2     �Խڵ�0 Ϊ���� �ڵ�0���Һ��ӣ�ֱ�Ӻ�̾����Һ���4
				 / \       ���ڵ�4û�����ӣ�ֱ�ӷ���  
				 3  4   ���ڽڵ�4 ���ԣ�û�����Һ��ӣ��Ҹýڵ㱾������Һ���
				           ���ظ��ڵ� 0�����ڵ�0�����Һ��ӣ��ٷ����丸�ڵ����1
                            				 
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
	else          //��ӹ�ע�ҽڵ��ԭ����ǣ�������������һ����Ԫ�ؾ����Һ���
	{
		while (IsRChild(*s))
			s = s->parent;
		s = s->parent;
	}

	return s;
}