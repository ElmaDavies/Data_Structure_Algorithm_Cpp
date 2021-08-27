#pragma once
template<typename T>
void List<T>::traverse()
{
	for (listnode<T>* p = header->succ; p != tailer; p = p->succ)
	{
		std::cout << p->data << "->";
	}
}
