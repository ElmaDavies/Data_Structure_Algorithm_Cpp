#pragma once
template<typename T>
bool List<T>::empty()
{
	if (m_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}