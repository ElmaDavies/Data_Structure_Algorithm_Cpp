#pragma once

#define stature(p) ((p)?(p)->height:-1) //�ڵ�߶ȣ�����Ϊ-1
typedef enum {RB_RED,RB_BLACK} RBColor; //�ڵ���ɫ

template<typename T> struct BinNode {

	T data; //��ֵ
	BinNode<T>* parent; //���ڵ�
	BinNode<T>* lc; //���ӽڵ�
	BinNode<T>* rc; //���ӽڵ�
	int height; //�߶�
	int npl; //NULL path height
	RBColor color; //��ɫ�������
	BinNode():  //���캯��
		parent(nullptr), lc(nullptr), height(0), npl(1), color(RB_RED) {}
	BinNode(T e, BinNode<T>* p = nullptr, BinNode<T>* lc = nullptr, BinNode<T>* rc = nullptr, 
		int h = 0, int l = 1, RBColor c = RB_RED):
		data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {}
	int size; //ͳ�Ƶ�ǰ�ڵ�������
	BinNode<T>* insertAsLc(T const&); //��Ϊ��ǰ�ڵ�����Ӳ����½ڵ�
	BinNode<T>* insertAsRc(T const&); //��Ϊ��ǰ�ڵ���Һ��Ӳ����½ڵ�
	BinNode<T>* succ(); //ȡ��ǰ�ڵ��ֱ�Ӻ��
	bool operator<(BinNode<T>* const& bn) { return data < bn.data; }
	bool operator==(BinNode<T>* const& bn) { return data == bn.data; }

	//��������������--�ݹ�
	void travLevel(); //������α���
    void travePre(BinNode<T>* x); //�����������
	void travIn(BinNode<T>* x); //�����������
	void travePost(BinNode<T>* x); //�����������
	
	//������������������
	void travelPreIt(BinNode<T>* x);//���������������
	void travelInIt(BinNode<T>* x); //�����������
	void travelPostIt(BinNode<T>* x); //�����������

	
};

#include"binNode_implention.h"
