#pragma once
template <typename T>
listnode<T>* List<T>::Last()
{
	return tailer->pred;    //����β��
}