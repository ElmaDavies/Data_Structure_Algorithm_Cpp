#pragma once
template <typename T>
int List<T>::findElement(T const &e)
{
	int count = 0;
	listnode<T>* p = header; //��ʼ����ǰ�ڵ�Ϊͷ�ڵ�
	while ((p=p->succ)!=tailer)
	{
		if (p->data == e)
		{
			count++;
		}
		
	}

	return count;
}