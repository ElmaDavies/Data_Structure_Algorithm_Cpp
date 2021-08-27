#pragma once
template <typename T>
listnode<T>* List<T>::find(T const& e, int n, listnode<T>* p) const
{
	while (0 < n--)
	{
		if (e == (p = p->pred)->data)
		{
			return p;
		}
		

	}

	return nullptr;
}