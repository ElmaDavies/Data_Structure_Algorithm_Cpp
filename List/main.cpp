#include"list_test.h"

int main()
{
	listnode<int>* p = new listnode<int>(0,NULL,NULL);
	
	List<int>* list = new List<int>();
	list->init();
	cout << list->m_size << endl;
	cout << p->data << endl;
	cout << p->pred << endl;
	cout << list->header->data<< endl;
	cout << list->find(0, 0, p) << endl;
	cout << list->insertFirst(3) << endl;
	cout << list->insertA(list->insertFirst(2), 2)<< endl;
	cout << list->operator[](1) << endl;
	listnode<int>* node = list->insertLast(1);
	cout << list->m_size << endl;
	list->traverse();
	cout << endl;
	//list->insertSort(list->header->succ,list->m_size);
	list->mergeSort(list->header->succ, list->m_size);
	list->traverse();
	cout <<endl<< "----×î´óÖµ-----" << endl;
	cout<<list->getMax(list->header->succ,list->m_size)->data<<endl;
	//cout << list->m_size << endl;
	//cout << node << endl;
	system("color 0a");
	system("pause");
	return 0;
}