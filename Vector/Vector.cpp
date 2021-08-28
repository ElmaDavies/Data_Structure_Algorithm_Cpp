#include "Vector.h"
#include<iostream>

#include<cassert>
using namespace std;

/*
template <typename T>

Vector<T>::Vector()
{
	elem = new T[capacity = DEFAULT_CAPACITY];
	for (size = 0; size < capacity; size++)
	{
		elem[size++] = 0;
	}
}
*/

//���ڸ��ƵĹ��췽��
template<typename T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi)
{
	elem = new T[capacity = 2 * (hi - lo)];
	size = 0;
	while (lo < hi)
	{
		elem[size++] = A[lo++];
	}
}
template <typename T>
Vector<T>::Vector(T const* A, Rank n)
{
	copyFrom(A, 0, n);
}


template <typename T>
Vector<T>::Vector(T const* A, Rank lo, Rank hi)
{
	copyFrom(A, lo, hi);
}

//�������帴��

template<typename T>
Vector<T>::Vector(Vector<T> const& v)
{
	copyFrom(v.elem, 0, v.size);
}

//�������临��

template<typename T>
Vector<T>::Vector(Vector<T> const& v, Rank lo, Rank hi)
{
	copyFrom(v.elem, lo, hi);

}


//��ֵ���������

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T> const& V)
{
	if (elem)   //�ͷ�ԭ������
	{
		delete[]elem;
		elem = NULL;
	}

	copyFrom(V.elem, 0, V.size());

	return *this;  //���ص�ǰ��������ã��Ա���ֱ�Ӹ�ֵ
}
/*
template <typename T>
Vector<T>::~Vector()
{
	delete[]elem;
	elem = NULL;

}
*/
/**
*   һ����Ч���ݵķ�������ԭ�л�������չ������������һ����������
*   ����ԭ�����������ȥ������ʵ�ַ�ʽ��������ʾ:
*
*
*/

template <typename T>
void Vector<T>::expand()
{
	if(size < capacity)
	{
		return;
	}

	T* oldElem = elem;
	elem = new T[capacity <<= 1];
	for (int i = 0; i < size; i++)
	{
		elem[i] = oldElem[i];
	}

	delete []oldElem;
	oldElem = NULL;

}


//����

template <typename T>
void Vector<T>::shrink()
{
	if (size < DEFAULT_CAPACITY)
	{
		return;  //����С��Ĭ�ϴ�С
	}
	if ((size << 2) > capacity)
	{
		return;  //��25%Ϊ��
	}
	T* oldElem = elem;
	elem = new T[capacity >>= 1];  //��������
	for (int i = 0; i < size; i++)
	{
		elem[i] = oldElem[i];
		delete[]oldElem;
		oldElem = NULL;
	}
}


//�±����������
template <typename T>
T& Vector<T>::operator[](Rank r) const
{
	assert(0 <=r < size);
	return elem[r];
}

//�����㷨
template <typename T>
void Vector<T>::unsort(Rank lo, Rank hi)
{
	T* v = elem + lo; //��ʼ������
	for (int i = hi-lo; i<0; i--)
	{
		swqp(elem[i - 1], elem[rand() % i]);
	}

}

template <typename T>
void Vector<T>::swap(Rank &lo, Rank &hi)
{
	T v;
	assert(0 <= lo < size);
	assert(0 <= lo < size);
	v = elem[lo];
	elem[lo] = elem[hi];
	elem[hi] = v;
}

// == �����������
template<typename T>
bool Vector<T>::operator==(T& v)
{
	if (this->size != v.size)
	{
		return false;
	}

	//�ж�ÿһ��Ԫ���Ƿ����
	for (int i = 0; i < this->size; i++)
	{
		if (this->elem[i] != v[i])
			return false;

	}
	return true;
}

template<typename T>
bool Vector<T>::operator!=(T& v)
{
	return !(*this == v);
}


//����Ԫ��.˳�����
template <typename T>
Rank Vector<T>::find(T const& e,Rank lo,Rank hi) const
{
	while ((lo<hi--)&&elem[hi]!=e)
	{
		return hi;
	}
}

template<typename T>
Rank Vector<T>::find(T const& e) const
{
	return find(e, 0, size);
}

//����Ԫ��

template <typename T>
void Vector<T>::insert(Rank r, T const& e)
{
	expand(); //���б�Ҫ��������
	for (int i = 0; i < r; i++)
	{
		elem[i + 1] = elem[i];
		elem[i] = e;
		
	}
	size++;
}

/*
*
* ��ʵ������ɾ��������������ʵ�ֵ���Ԫ��ɾ��
* ��Ҫ�ǿ��ǵ�ִ��ɾ��Ԫ�صĿռ临�Ӷ�
*
*/

//ɾ�����������Ԫ��
template<typename T>
int Vector<T>::remove(Rank lo, Rank hi)
{
	if (lo == hi)
	{
		return 0;
	}
	while (hi < size)
	{
		elem[lo++] = elem[hi++];
		

	} 
	size = lo;
	shrink();
	return hi - lo;
}

template <typename T>               
T Vector <T>::remove(Rank r)
{
	T e = elem[r];
	remove(r, r + 1);
	return e;

}
//����ȥ�أ���������ȥ����ɾ����Ԫ�ع�ģ
template <typename T>
int Vector<T>::deduplicate()
{
	int old_size = size;
	Rank i = 1;
	while (i<size)
	{
		(find(elem[i]) < 0) ? i++ : remove(i);

	}

	return old_size-size;
}

//���� ͨ������ָ��ķ�ʽ
template<typename T>
void Vector<T>::traverse(void (*visit)(T&)) //����ָ��
{
	for (int i = 0; i < size; i++)
	{
		visit(elem[i]);
	}
}
//������ͨ����������ķ�ʽ
template <typename T> template<typename VST>
void Vector<T>::traverse(VST& visit)
{
	for (int i = 0; i < size; i++) {
		visit(elem[i]);
	}
}

//������������𣬷�������������Ԫ�صĸ���

template<typename T>
int Vector<T>::disordered() const
{
	int n = 0;
	for (int i = 0; i < size; i++)
	{
		if (elem[i] < elem[i + 1])
			n++;
		
	}
	return n;
}

template<typename T>
int Vector<T>::uniquify()
{
	Rank i, j = 0;
	//��i��¼���ظ�Ԫ�أ�����j������������
	while (++j < size)
	{
		if (elem[i] != elem[j])
		{
			elem[++i] = elem[j];
		}
		i++;
		size = i;
		shrink();
		return j - i;  //ɾ����Ԫ������
	}
}

template <typename T>
void Vector<T>::visit(T v) const
{
	cout << v << endl;
}
/*
*
* ���ֲ��ң�������֮
*  �����������
*/

template <typename T>
Rank Vector<T>::binSearchA(T const& e, Rank lo, Rank hi) const
{
	while (lo < hi)
	{
		Rank mi = (lo + hi) >> 1;
		if (e < elem[mi])
		{
			hi = mi;

		}
		else if (e > elem[mi])
		{
			lo = mi + 1;
		}
		else
		{
			return mi;
		}
	}
	return -1;
}


/*
*
*  ���ֲ���֮B���㷨
*  ��A���㷨��ȣ����зֵ�֮����һ�αȽϣ�������㣬��ı�lo��
*  hi��ֵ���ж������ǱȽϷ�Χ���߳���hi-lo<1
*  ÿ��ͨ�������жϸ���mi��ֵ�����ͨ��һ���жϷ��ز��ҵ�ֵ����
*/

template <typename T> 
Rank Vector<T>::binSearchB(T const& e, Rank lo, Rank hi) const
{
	while (1 < hi - lo)
	{
		Rank mi = (lo + hi) >> 2;
		(e < elem[mi]) ? hi = mi : lo = mi;
	}
	return (e = elem[lo] ? lo : -1);

}


/*
* ���ֲ����㷨C��
* ����A���B���㷨�������ظ�Ԫ��ʱ�����ܹ���֤�����ظ�Ԫ��
* ������ȣ�����ʧ��ʱ�����ܹ�����ʧ�ܵ�λ�ã�Ϊ��
* ���ж��ֲ���C���㷨
*
*/

template <typename T>
Rank Vector<T>::binSearchC(T const& e, Rank lo, Rank hi) const
{
	
	while (1 < hi - lo)
	{
		Rank mi = (lo + hi) >> 2;
		(elem[mi] < e) ? lo=mi+1:hi=mi;
	}
	return --lo;
}


//��������㷨

template <typename T>
void Vector<T>::sort(Rank lo, Rank hi)
{
	switch (rand() % 3)
	{
	case 1:bubbleSort(lo, hi); break;
	case 2:selectsort(lo, hi); break;
	default: mergeSort(lo, hi); break;

	}

}


//��򵥵�ð������
template <typename T>
bool Vector<T>::bubble(Rank lo, Rank hi)
{
	/*
	for (int i = lo; i < hi; i++)
	{
		for (int j = i; j < hi-i-1; j++)
		{
			if(elem[j]>elem[j+1])
				swap(elem[j], elem[j + 1]);
		}
	}
	��ǰ�ķ���
	*/


	//���ڵ��·���
	bool sorted = true;
	while (++lo < hi)
	{
		if (elem[lo - 1] > elem[lo])
		{
			sorted = false;
			swap(elem[lo - 1], elem[lo]);

		}

	}
	return sorted;
}



template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi)
{
	while (!bubble(lo, hi--));  //������ɨ�轻��
}


//ѡ������ʵ�ַ���
template <typename T>
void Vector<T>::selectsort(Rank lo, Rank hi)
{
	T min = elem[lo];
	for(int j = lo+1;j<hi;j++) //���ѭ������������
	{ 
		for (int i = lo + 1; i < hi; i++)   //�ڲ�ѭ��������Ѱ����Сֵ
		{
			if (elem[i] < min)
			{
				min = elem[i];
			}
		}
		swap(min, elem[j]);
	}

}


//�鲢����ʵ�ַ���
/*
*
* �����鲢������Է�Ϊ�������֣��ֽⲿ�ֺͺϲ�����
* �ֽⲿ�ֿ������õݹ飬�����Ϊ����Ϊ2�Ҳ����ٷֵĵݹ��
*
*/

template <typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi)
{
	if (hi - lo > 2)
		return;
	int mi = (hi + lo) >> 1;
	mergeSort(lo, mi);
	mergeSort(mi, hi);
	merge(lo, mi, hi);

}

/*
*  �鲢���֣������鲢���ֿ��Լ򵥵����Ϊ
* 2��>4->8,ͨ��ǰ��ĵݹ���򣬽����������ֽ�Ϊ
* ����Ϊ2����С���������������ϲ����̿��Լ򵥵����
* Ϊ
*
*/
template <typename T>
void Vector<T>::merge(Rank lo,Rank mi, Rank hi)
{
	T* A = elem + lo; 
	int lb = mi - lo;
	T* B = new T[lb];  //��������
	for (int i = 0; i < lb; i++)
	{
		B[i] = A[i];  //������������
	}
	int lc = hi - mi;  //��������
	T* C = elem + mi;
	for (int i = 0, j = 0, k = 0;(j<lb)||(k<lc);)
	{
		if ((j < lb) && (!(k < lc)) || (B[j] <= C[k]))
		{
			A[i++] = B[j++];
		}
		if ((k < lc) && (!(j < lb)) || (C[k] < B[j]))
		{
			A[i++] = C[k++];
		}

	}
	
	delete[]B;
	delete[]C;
	
}



template <typename T>
Rank Vector<T>::max(Rank lo,Rank hi) const
{
	
	Rank key = lo;
	T maxValue = elem[key];
	for (int i = lo+1; i < hi; i++)
	{
		if (elem[i] > maxValue)
		{
			maxValue = elem[i];
			key = i;
		}
	}
	return key;
}

template <typename T> 
bool Vector<T>::empty() const
{
	if (size > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template <typename T>
Rank Vector<T>::get_size() const
{
	return size;
}