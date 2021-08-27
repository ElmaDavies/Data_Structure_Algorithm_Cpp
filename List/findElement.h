#pragma once
template <typename T>
int List<T>::findElement(T const &e)
{
	int count = 0;
	listnode<T>* p = header; //初始化当前节点为头节点
	while ((p=p->succ)!=tailer)
	{
		if (p->data == e)
		{
			count++;
		}
		
	}

	return count;
}