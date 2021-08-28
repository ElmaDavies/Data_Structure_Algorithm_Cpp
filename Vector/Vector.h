#pragma once
#ifndef _VECTOR_H_
#define _VECTOR_H_

typedef int Rank;
#define DEFAULT_CAPACITY 3
template<typename T> class Vector
{
protected:
	Rank size;  //当前大小
	int capacity; //容量
	T* elem;       //数据
	void copyFrom(T const* A, Rank lo, Rank hi); //复制数组区间A[lo,hi]
	void expand(); //空间不足时扩容
	void shrink(); //压缩空间
	void bubbleSort(Rank lo, Rank hi);//冒泡，外层循环
	bool bubble(Rank lo,Rank hi); //排序,内层循环
	Rank max(Rank lo, Rank hi) const; //获取最大元素
	void selectsort(Rank lo, Rank hi);//排序算法
	void merge(Rank lo, Rank mi, Rank hi); //归并算法
	void mergeSort(Rank lo, Rank hi); //归并排序算法
//	void partition(Rank lo, Rank hi); //轴点构造算法
//	void quickSort(Rank lo, Rank hi); //快速排序算法
//	void heapSort(Rank lo, Rank hi); //堆排序算法
public:
	//构造函数
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
	
	//区间复制
	Vector(Vector<T> const& v);
	Vector(Vector<T> const& v, Rank lo, Rank hi);
	  //向量整体与区间复制

	~Vector() { delete[]elem; } // 析构函数

	//只读访问接口
	Rank get_size() const;
	bool empty() const; //判空
	int disordered() const; //判断排序
	Rank find(T const& e) const; //无序查找
	Rank find(T const& e, Rank lo, Rank hi) const; //无序区间查找
	
	Rank binSearchC(T const& e, Rank lo, Rank hi) const;
	Rank binSearchC(T const& e)
	{
		return binSearchC(e, 0, size);
	}
	Rank binSearchA(T const& e, Rank, Rank hi) const;//二分查找
	Rank binSearchB(T const& e, Rank lo, Rank hi) const; //B版二分查找

	//可写访问接口
	bool operator==(T &v); //比较运算符的重载
	bool operator!=(T& v); 
	T& operator[](Rank r) const; //下标运算发重载
	Vector<T>& operator=(Vector<T> const&); //重新复制运算符重载
	T  remove(Rank r); //删除秩为r的单个元素
	int remove(Rank lo,Rank hi);
	void insert(Rank r, T const& e); //插入元素
	void insert(T const& e) { return insert(size, e); } //默认插入队尾
	void sort(Rank lo, Rank hi); //[lo,hi] 进行排序
	void sort() { sort(0, size); }
	void unsort(Rank lo, Rank hi); //对	区间[lo,hi]置乱
	void unsort() { unsort(0, size); } //对整个区间置乱
	int deduplicate(); //无序去重
	int uniquify(); //有序去重
	void swap(Rank &lo, Rank &hi);//交换两个指定下标的元素
	//遍历

	void traverse(void (*visit)(T&)); //遍历
	template <typename VST> void traverse(VST&);
	void visit(T v) const;
 	
	//Vector();

};




//#include "Vector.tpp"
#endif // !VECTOR
