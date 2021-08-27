#pragma once
#include<iostream>
template <typename T>
struct listnode
{
	T data;
	listnode<T>* pred;
	listnode<T>* succ;

	listnode() {}
	listnode(T e, listnode<T>* p = NULL, listnode<T>* s = NULL)
		:data(e), pred(p), succ(s) {}
	listnode<T>* insertAspred(T const& e);
	listnode<T>* insertAssucc(T const& e);
};