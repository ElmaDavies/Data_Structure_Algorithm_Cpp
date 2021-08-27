#pragma once
template <typename T>
listnode<T>* List<T>::getMax(listnode<T>*p,int n) const
{
	listnode<T>* max = p;
	
	while (1 < n)
	{
		if ((p= p -> succ)->data >= max->data)
		{
			max = p;

		}
		
		n--;
	}
	return max;
}
