#include"queue.h"
#include<iostream>
using namespace std;

int main()
{
	Queue<int>	q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.traverse();
	cout << q.getSize() << endl;
	cout << q.dequeue() << endl;
	cout << q.front() << endl;
	system("pause");
	return 0;
}