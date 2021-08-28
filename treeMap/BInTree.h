#pragma once
#include"binNode.h"

template <typename T> class BinTree
{
protected :
	int m_size; //规模
	BinNode<T>* _root; //根节点
   virtual int updateHeight(BinNode<T>* x); //更新节点x的高度 
	/*虚函数，用基类的指针或者引用调用时，实际上调用的是继承类的版本*/

	void updateHeightAbove(BinNode<T>* x);//更新节点x机器祖先的高度
public:
	BinTree() :m_size(0), _root(nullptr){}
	~BinTree()
	{
		if (m_size > 0)
			remove(_root);
	}
	int size() const { return m_size; }
	bool empty() const { return !_root; } //判空
	BinNode<T>* root() const { return _root; }
	BinNode<T>* insertAsRoot(T const& e); //插入根节点
	BinNode<T>* insertAsLc(BinNode<T>* x, T const &e); //作为左孩子插入
	BinNode<T>* insertAsRc(BinNode<T>* x, T const& e);
	BinNode<T>* attachAsLc(BinNode<T>* x, BinTree<T>* &T); //作为左子树接入
	BinNode<T>* attachAsRc(BinNode<T>* x, BinTree<T>*& T);// T作为右子树接入
	int remove(BinNode<T>* x); //删除节点为根的子树
	BinTree<T>* secede(BinNode<T>* x); //将子树从当前节点删除，并将其转化为一颗独立子树
	int max(int a, int b);
	//二叉树的递归遍历
	void traveLevel() { if (_root) _root->travLevel(); }
	void travelPre() { if (_root) _root->travePre(_root); }
	void travelPost() { if (_root) _root->travePost(_root); }
	void travIn() { if (_root) _root->travIn(_root); }


	//二叉树的迭代遍历
	void travelPreIt() { if (_root) _root->travelPreIt(_root); } //迭代前序遍历
	void travelInIt() { if (_root) _root->travelInIt(_root); } //迭代中序遍历
	void travelPostIt() { if (_root) _root->travelPostIt(_root); } //迭代中的后序遍历
};



#include"binTree_implention.h"