#pragma once
#include "../list/list.h"

/*
*   公有继承list
*
*
*
*/
template <typename T> class Stack : public List<T>
{

public:
	void push(T const& e) {(*this).insertLast(e); }  //入栈
	T pop() {
		return (*this).listremove((*this).Last());   //出栈
	}

	T& top() { return ((*this).Last())->data; } //取出栈顶元素
	
	
};

