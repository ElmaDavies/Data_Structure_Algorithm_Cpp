#pragma once
template <typename T>
listnode<T>* List<T>::First()
{
	return header->succ;
}