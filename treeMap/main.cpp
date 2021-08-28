#include"tree_test.h"



int main()
{
	BinTree<int> *a =new BinTree<int>();
	BinTree<int>* b = new BinTree<int>();
	b->insertAsRoot(0);
	b->insertAsLc(b->root(), 2);
	b->insertAsRc(b->root(), 2);
	cout << b->size() << endl;
	cout << a->size() << endl;
	cout << a << endl;
	cout << a->empty() << endl;
	a->insertAsRoot(1);
	a->insertAsLc(a->root(),1);
	a->insertAsRc(a->root(), 2);
	cout << a->root()->data << endl;
	cout << a->empty() << endl;
	cout << a->size() << endl;
	a->attachAsLc(a->root(),b);
	cout << a->size() << endl;
	cout << "���ö���ʵ�ֵĲ�α�����" << endl;
	a->traveLevel();
	cout << endl;
	cout << "�ݹ�ʵ�ֵ�ǰ�������" << endl;
	a->travelPre();
	cout << "�ݹ�ʵ�ֵĺ������" << endl;
	cout << endl;
	a->travelPost();
	cout << endl;
	cout << "�ݹ�ʵ�ֵ��������" << endl;
	cout << endl;
	a->travIn();
	cout << endl;
	cout << "����ʵ�ֵ�ǰ�����" << endl;
	a->travelPreIt();
	cout << endl;
	cout << "����ʵ�ֵ��������" << endl;
	a->travelInIt();
	cout << endl;
	//cout << a->root()->succ()->succ()->data << endl;
	cout << endl;
	cout << "����ʵ�ֵĺ������" << endl;
	a->travelPostIt();
	cout << endl;
	system("pause");
	return 0;
}