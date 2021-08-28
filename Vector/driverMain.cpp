#include"Vector.h"
#include<iostream>

using namespace std;
//template <typename T>
//template class Vector<int>;
int main()
{
	Vector<int> vect = Vector<int>(4,2,1);
	cout << vect.get_size() << endl;
	system("pause");
	return 0;
}