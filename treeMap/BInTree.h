#pragma once
#include"binNode.h"

template <typename T> class BinTree
{
protected :
	int m_size; //��ģ
	BinNode<T>* _root; //���ڵ�
   virtual int updateHeight(BinNode<T>* x); //���½ڵ�x�ĸ߶� 
	/*�麯�����û����ָ��������õ���ʱ��ʵ���ϵ��õ��Ǽ̳���İ汾*/

	void updateHeightAbove(BinNode<T>* x);//���½ڵ�x�������ȵĸ߶�
public:
	BinTree() :m_size(0), _root(nullptr){}
	~BinTree()
	{
		if (m_size > 0)
			remove(_root);
	}
	int size() const { return m_size; }
	bool empty() const { return !_root; } //�п�
	BinNode<T>* root() const { return _root; }
	BinNode<T>* insertAsRoot(T const& e); //������ڵ�
	BinNode<T>* insertAsLc(BinNode<T>* x, T const &e); //��Ϊ���Ӳ���
	BinNode<T>* insertAsRc(BinNode<T>* x, T const& e);
	BinNode<T>* attachAsLc(BinNode<T>* x, BinTree<T>* &T); //��Ϊ����������
	BinNode<T>* attachAsRc(BinNode<T>* x, BinTree<T>*& T);// T��Ϊ����������
	int remove(BinNode<T>* x); //ɾ���ڵ�Ϊ��������
	BinTree<T>* secede(BinNode<T>* x); //�������ӵ�ǰ�ڵ�ɾ����������ת��Ϊһ�Ŷ�������
	int max(int a, int b);
	//�������ĵݹ����
	void traveLevel() { if (_root) _root->travLevel(); }
	void travelPre() { if (_root) _root->travePre(_root); }
	void travelPost() { if (_root) _root->travePost(_root); }
	void travIn() { if (_root) _root->travIn(_root); }


	//�������ĵ�������
	void travelPreIt() { if (_root) _root->travelPreIt(_root); } //����ǰ�����
	void travelInIt() { if (_root) _root->travelInIt(_root); } //�����������
	void travelPostIt() { if (_root) _root->travelPostIt(_root); } //�����еĺ������
};



#include"binTree_implention.h"