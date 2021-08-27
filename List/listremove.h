#pragma once

template<typename T>
T List<T>::listremove(listnode<T>* p)
{
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	m_size--;
	return e;
}
