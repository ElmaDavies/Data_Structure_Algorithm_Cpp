#pragma once
#include "../list/list.h"

/*
*   ���м̳�list
*
*
*
*/
template <typename T> class Stack : public List<T>
{

public:
	void push(T const& e) {(*this).insertLast(e); }  //��ջ
	T pop() {
		return (*this).listremove((*this).Last());   //��ջ
	}

	T& top() { return ((*this).Last())->data; } //ȡ��ջ��Ԫ��
	
	
};

