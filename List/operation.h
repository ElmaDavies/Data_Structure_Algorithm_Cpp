#pragma once
//�����±������
//#include"list.h"
template <typename T>
T& List<T>::operator[](int r) const
{
	listnode<T>* p = header;
	while (0 < r--)
	{
		p = p->succ;
	}
	return p->data;
}