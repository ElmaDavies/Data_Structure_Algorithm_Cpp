#pragma once
template<typename T>
listnode<T>* List<T>::search(T const& e, int n, listnode<T>* p) const
{

	//��p��ʼ�Ӻ���ǰ���ң�ֱ���ҵ����Ԫ�أ���<=�ж�
	
	
		while (0 <= n--)
		{
			p = p->pred;
			if ((p->data) <= e) break;
			
			
		}
	
	return p;
}