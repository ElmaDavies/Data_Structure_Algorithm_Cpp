#pragma once
#include"../list/list.h"
template <typename T> class Queue :public List<T>
{
public:
	void enqueue(T const& e) { (*this).insertFirst(e); }
	T dequeue() { return (*this).listremove((*this).Last()); }
	T& front() { return (*this).First()->data; }  //取出队头；
};

#include"queue_implention.h"