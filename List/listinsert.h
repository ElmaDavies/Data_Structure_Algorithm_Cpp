#pragma once
template<typename T>
listnode<T>* List<T>::insertFirst(T const& e)
{
	m_size++;
	return header->insertAssucc(e);
}

template<typename T>
listnode<T>* List<T>:: insertLast(T const& e)
{
	m_size++;
	return tailer->insertAspred(e);

}
template<typename T>
listnode<T>* List<T>::insertA(listnode<T>* p, T const& e)
{
	
	m_size++;
	return p->insertAspred(e);
}
template<typename T>
listnode<T>* List<T>::insertB(listnode<T>* p, T const& e)
{
	m_size++;
	return p->insertAssucc(e);
}