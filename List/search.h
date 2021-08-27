#pragma once
template<typename T>
listnode<T>* List<T>::search(T const& e, int n, listnode<T>* p) const
{

	//从p开始从后往前查找，直到找到这个元素，用<=判断
	
	
		while (0 <= n--)
		{
			p = p->pred;
			if ((p->data) <= e) break;
			
			
		}
	
	return p;
}