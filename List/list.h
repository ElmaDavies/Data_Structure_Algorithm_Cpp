#pragma once
#include "listnode.h"

template <typename T>
class List
{

public:
	listnode<T>* header;
	int m_size;
	listnode<T>* tailer;
public:
	void init();
	void clear();
	List() { init(); }
	T& operator[](int r) const; //index operator
	//find element between size n and node p
	listnode<T>* find(T const& e, int n, listnode<T>* p) const;
	//insert element for list as pred node
	listnode <T>* insertFirst(T const& e); //当做首节点插入
	listnode<T>* insertLast(T const& e); //插入尾节点之前
	listnode<T>* insertA(listnode<T>* p, T const& e); //p节点之前插入
	listnode<T>* insertB(listnode <T>* p, T const& e); //B节点之后插入
	T listremove(listnode<T>* p);
	~List() { clear(); delete header; delete tailer; }
	int depulicate(); //去除链表中的重复元素
	void traverse(); //函数指针遍历
	void sort(listnode<T>* p, int n);  //排序
	void selectSort(listnode<T>* p, int n);
	void insertSort(listnode<T>* p, int n);
	void mergeSort(listnode<T>* p, int n);
	listnode<T>* search(T const& e, int n, listnode<T>* p) const;
	//向量的有序搜索
	listnode<T>* getMax(listnode<T>* p,int n) const;
	void merge(listnode<T>* &p, int n, List<T>& L, listnode<T>* q, int m);
	int getSize()  const;
	listnode<T>* Last();
	listnode<T>* First();
	bool empty(); //判断是否为空
	int findElement(T const &e); //查找相同元素，返回相同元素的个数
};

#include"list_implemention.h"