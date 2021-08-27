#pragma once
template <typename T>
void List<T>::sort(listnode<T>* p, int n)
{
	switch (rand() % 1)
	{
	case 0:
		insertSort(p, n);
		break;
	case 1:
		selectSort(p, n);
		break;
	default:
		mergeSort(p, n);
		break;

	}
}

template <typename T>
void List<T>::insertSort(listnode<T>* p, int n)
{
	int i = 0;
	while (i < n)
	{
		insertB(search (p->data,i,p), p->data);// 
		p = p->succ;
		listremove(p->pred);
		i++;
	}
}

template <typename T>
void List<T>:: mergeSort(listnode<T>* p, int n)
{
	if (n < 2) return;
	int m = n >> 1;
	listnode<T>* q = p;
	for (int i = 0; i < m; i++)
	{
		q = q->succ;
	}
	mergeSort(p, m);
	mergeSort(q, n-m);
	merge(p, m, *this, q, n - m);
}
template <typename T>
void List<T>::selectSort(listnode<T>* p, int n)
{
	listnode<T>* head = p->pred;
	listnode<T>* tail = p;
	for (int i = 0; i < n; i++)
	{
		tail = tail->succ;
	}
	//跳到尾节点，构成一个长度为n，区间为（head,tail）
	while (1 < n)
	{
		listnode<T>* max = getMax(head->succ, n);
		insertA(tail, listremove(max));
		tail = tail->pred;
		n--;
	}
	
}

template <typename T>
void List<T>::merge(listnode<T>* &p, int n, List<T>& L, listnode<T>* q, int m)
{
	listnode <T>* pp = p->pred;
	while (0 < m)
	{
		if ((0 < n) && (p->data <= q->data))
		{
			if (q == (p = p->succ))
				break;
			n--;
		}
		else
		{
			insertA(p, L.listremove((q = q->succ)->pred));
			m--;

		}
		
	}
	p = pp->succ;
}