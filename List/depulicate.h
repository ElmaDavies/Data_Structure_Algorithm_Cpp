#pragma once
template <typename T>
int List<T>::depulicate()
{
	int oldsize = m_size;
	int r = 0; //���б���׽ڵ㿪ʼ��Ѱ
	if (m_size < 2) return 0;
	listnode<T>* p = header;
	while (tailer!=(p =p->succ))
	{
		listnode<T>* q = find(p->data, r, p);
		q ? listremove(q) : r++;

	}
	return oldsize-m_size;
}
