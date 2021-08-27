#pragma once
template <typename T>
void List<T>::clear()
{
	while (0 < m_size)
		listremove(header->succ);
		
}