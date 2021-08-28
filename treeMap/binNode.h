#pragma once

#define stature(p) ((p)?(p)->height:-1) //节点高度，空树为-1
typedef enum {RB_RED,RB_BLACK} RBColor; //节点颜色

template<typename T> struct BinNode {

	T data; //数值
	BinNode<T>* parent; //父节点
	BinNode<T>* lc; //左子节点
	BinNode<T>* rc; //右子节点
	int height; //高度
	int npl; //NULL path height
	RBColor color; //颜色，红黑树
	BinNode():  //构造函数
		parent(nullptr), lc(nullptr), height(0), npl(1), color(RB_RED) {}
	BinNode(T e, BinNode<T>* p = nullptr, BinNode<T>* lc = nullptr, BinNode<T>* rc = nullptr, 
		int h = 0, int l = 1, RBColor c = RB_RED):
		data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {}
	int size; //统计当前节点后代总数
	BinNode<T>* insertAsLc(T const&); //作为当前节点的左孩子插入新节点
	BinNode<T>* insertAsRc(T const&); //作为当前节点的右孩子插入新节点
	BinNode<T>* succ(); //取当前节点的直接后继
	bool operator<(BinNode<T>* const& bn) { return data < bn.data; }
	bool operator==(BinNode<T>* const& bn) { return data == bn.data; }

	//二叉树遍历方法--递归
	void travLevel(); //子树层次遍历
    void travePre(BinNode<T>* x); //子树先序遍历
	void travIn(BinNode<T>* x); //子树中序遍历
	void travePost(BinNode<T>* x); //子树后序遍历
	
	//二叉树遍历，迭代版
	void travelPreIt(BinNode<T>* x);//子树迭代先序遍历
	void travelInIt(BinNode<T>* x); //子树中序遍历
	void travelPostIt(BinNode<T>* x); //子树后序遍历

	
};

#include"binNode_implention.h"
