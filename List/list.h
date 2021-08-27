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
	listnode <T>* insertFirst(T const& e); //�����׽ڵ����
	listnode<T>* insertLast(T const& e); //����β�ڵ�֮ǰ
	listnode<T>* insertA(listnode<T>* p, T const& e); //p�ڵ�֮ǰ����
	listnode<T>* insertB(listnode <T>* p, T const& e); //B�ڵ�֮�����
	T listremove(listnode<T>* p);
	~List() { clear(); delete header; delete tailer; }
	int depulicate(); //ȥ�������е��ظ�Ԫ��
	void traverse(); //����ָ�����
	void sort(listnode<T>* p, int n);  //����
	void selectSort(listnode<T>* p, int n);
	void insertSort(listnode<T>* p, int n);
	void mergeSort(listnode<T>* p, int n);
	listnode<T>* search(T const& e, int n, listnode<T>* p) const;
	//��������������
	listnode<T>* getMax(listnode<T>* p,int n) const;
	void merge(listnode<T>* &p, int n, List<T>& L, listnode<T>* q, int m);
	int getSize()  const;
	listnode<T>* Last();
	listnode<T>* First();
	bool empty(); //�ж��Ƿ�Ϊ��
	int findElement(T const &e); //������ͬԪ�أ�������ͬԪ�صĸ���
};

#include"list_implemention.h"