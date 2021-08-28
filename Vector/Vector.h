#pragma once
#ifndef _VECTOR_H_
#define _VECTOR_H_

typedef int Rank;
#define DEFAULT_CAPACITY 3
template<typename T> class Vector
{
protected:
	Rank size;  //��ǰ��С
	int capacity; //����
	T* elem;       //����
	void copyFrom(T const* A, Rank lo, Rank hi); //������������A[lo,hi]
	void expand(); //�ռ䲻��ʱ����
	void shrink(); //ѹ���ռ�
	void bubbleSort(Rank lo, Rank hi);//ð�ݣ����ѭ��
	bool bubble(Rank lo,Rank hi); //����,�ڲ�ѭ��
	Rank max(Rank lo, Rank hi) const; //��ȡ���Ԫ��
	void selectsort(Rank lo, Rank hi);//�����㷨
	void merge(Rank lo, Rank mi, Rank hi); //�鲢�㷨
	void mergeSort(Rank lo, Rank hi); //�鲢�����㷨
//	void partition(Rank lo, Rank hi); //��㹹���㷨
//	void quickSort(Rank lo, Rank hi); //���������㷨
//	void heapSort(Rank lo, Rank hi); //�������㷨
public:
	//���캯��
	Vector(T const* A, Rank n);
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)
	{
		elem = new T[capacity = c];
		for (size = 0; size < c; size++)
		{
			elem[size] = v;
		}
	}
	
	Vector(T const* A, Rank lo, Rank hi);
	
	//���临��
	Vector(Vector<T> const& v);
	Vector(Vector<T> const& v, Rank lo, Rank hi);
	  //�������������临��

	~Vector() { delete[]elem; } // ��������

	//ֻ�����ʽӿ�
	Rank get_size() const;
	bool empty() const; //�п�
	int disordered() const; //�ж�����
	Rank find(T const& e) const; //�������
	Rank find(T const& e, Rank lo, Rank hi) const; //�����������
	
	Rank binSearchC(T const& e, Rank lo, Rank hi) const;
	Rank binSearchC(T const& e)
	{
		return binSearchC(e, 0, size);
	}
	Rank binSearchA(T const& e, Rank, Rank hi) const;//���ֲ���
	Rank binSearchB(T const& e, Rank lo, Rank hi) const; //B����ֲ���

	//��д���ʽӿ�
	bool operator==(T &v); //�Ƚ������������
	bool operator!=(T& v); 
	T& operator[](Rank r) const; //�±����㷢����
	Vector<T>& operator=(Vector<T> const&); //���¸������������
	T  remove(Rank r); //ɾ����Ϊr�ĵ���Ԫ��
	int remove(Rank lo,Rank hi);
	void insert(Rank r, T const& e); //����Ԫ��
	void insert(T const& e) { return insert(size, e); } //Ĭ�ϲ����β
	void sort(Rank lo, Rank hi); //[lo,hi] ��������
	void sort() { sort(0, size); }
	void unsort(Rank lo, Rank hi); //��	����[lo,hi]����
	void unsort() { unsort(0, size); } //��������������
	int deduplicate(); //����ȥ��
	int uniquify(); //����ȥ��
	void swap(Rank &lo, Rank &hi);//��������ָ���±��Ԫ��
	//����

	void traverse(void (*visit)(T&)); //����
	template <typename VST> void traverse(VST&);
	void visit(T v) const;
 	
	//Vector();

};




//#include "Vector.tpp"
#endif // !VECTOR
