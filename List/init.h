#pragma once
#include "list.h"
#include<iostream>
template <typename T>
void List<T>::init()
{
	header = new listnode<T>;
	tailer = new listnode<T>;
	header->succ = tailer;
	header->pred = NULL;
	tailer->succ = NULL;
	tailer->pred = header;
	m_size = 0;
}