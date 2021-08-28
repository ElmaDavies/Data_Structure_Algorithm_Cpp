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

//基于复制的构造方法
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

//向量整体复制

template<typename T>
Vector<T>::Vector(Vector<T> const& v)
{
	copyFrom(v.elem, 0, v.size);
}

//向量区间复制

template<typename T>
Vector<T>::Vector(Vector<T> const& v, Rank lo, Rank hi)
{
	copyFrom(v.elem, lo, hi);

}


//赋值运算符重载

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T> const& V)
{
	if (elem)   //释放原有内容
	{
		delete[]elem;
		elem = NULL;
	}

	copyFrom(V.elem, 0, V.size());

	return *this;  //返回当前对象的引用，以便于直接赋值
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
*   一种有效扩容的方法是在原有基础上扩展两倍，并生成一个新向量，
*   并将原来的向量搬过去，具体实现方式，如下所示:
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


//缩容

template <typename T>
void Vector<T>::shrink()
{
	if (size < DEFAULT_CAPACITY)
	{
		return;  //不得小于默认大小
	}
	if ((size << 2) > capacity)
	{
		return;  //以25%为界
	}
	T* oldElem = elem;
	elem = new T[capacity >>= 1];  //容量减半
	for (int i = 0; i < size; i++)
	{
		elem[i] = oldElem[i];
		delete[]oldElem;
		oldElem = NULL;
	}
}


//下标运算符重载
template <typename T>
T& Vector<T>::operator[](Rank r) const
{
	assert(0 <=r < size);
	return elem[r];
}

//置乱算法
template <typename T>
void Vector<T>::unsort(Rank lo, Rank hi)
{
	T* v = elem + lo; //开始的区间
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

// == 运算符的重载
template<typename T>
bool Vector<T>::operator==(T& v)
{
	if (this->size != v.size)
	{
		return false;
	}

	//判断每一个元素是否相等
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


//查找元素.顺序查找
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

//插入元素

template <typename T>
void Vector<T>::insert(Rank r, T const& e)
{
	expand(); //如有必要，先扩容
	for (int i = 0; i < r; i++)
	{
		elem[i + 1] = elem[i];
		elem[i] = e;
		
	}
	size++;
}

/*
*
* 先实现区间删除，再利用重载实现单个元素删除
* 主要是考虑到执行删除元素的空间复杂度
*
*/

//删除整个区间的元素
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
//无序去重，返回向量去重是删除的元素规模
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

//遍历 通过函数指针的方式
template<typename T>
void Vector<T>::traverse(void (*visit)(T&)) //函数指针
{
	for (int i = 0; i < size; i++)
	{
		visit(elem[i]);
	}
}
//遍历，通过函数对象的方式
template <typename T> template<typename VST>
void Vector<T>::traverse(VST& visit)
{
	for (int i = 0; i < size; i++) {
		visit(elem[i]);
	}
}

//向量有序行甄别，返回向量中有序元素的个数

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
	//用i记录不重复元素，而用j遍历整个向量
	while (++j < size)
	{
		if (elem[i] != elem[j])
		{
			elem[++i] = elem[j];
		}
		i++;
		size = i;
		shrink();
		return j - i;  //删除的元素总数
	}
}

template <typename T>
void Vector<T>::visit(T v) const
{
	cout << v << endl;
}
/*
*
* 二分查找，减而治之
*  针对有序向量
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
*  二分查找之B版算法
*  与A版算法相比，在切分点之进行一次比较，如果满足，则改变lo和
*  hi的值，判读条件是比较范围或者长度hi-lo<1
*  每次通过条件判断更新mi的值，最后通过一次判断返回查找的值得秩
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
* 二分查找算法C版
* 以上A版和B版算法，存在重复元素时，不能够保证返回重复元素
* 的最大秩，并且失败时并不能够返回失败的位置，为此
* 特有二分查找C版算法
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


//相关排序算法

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


//最简单的冒泡排序
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
	以前的方法
	*/


	//现在的新方法
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
	while (!bubble(lo, hi--));  //逐行做扫描交换
}


//选择排序实现方法
template <typename T>
void Vector<T>::selectsort(Rank lo, Rank hi)
{
	T min = elem[lo];
	for(int j = lo+1;j<hi;j++) //外层循环，用来交换
	{ 
		for (int i = lo + 1; i < hi; i++)   //内层循环，用来寻找最小值
		{
			if (elem[i] < min)
			{
				min = elem[i];
			}
		}
		swap(min, elem[j]);
	}

}


//归并排序实现方法
/*
*
* 整个归并排序可以分为两个部分，分解部分和合并部分
* 分解部分可以利用递归，将其分为长度为2且不可再分的递归基
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
*  归并部分，整个归并部分可以简单的理解为
* 2—>4->8,通过前面的递归程序，将整个向量分解为
* 长度为2的最小的子向量，整个合并过程可以简单的理解
* 为
*
*/
template <typename T>
void Vector<T>::merge(Rank lo,Rank mi, Rank hi)
{
	T* A = elem + lo; 
	int lb = mi - lo;
	T* B = new T[lb];  //左子向量
	for (int i = 0; i < lb; i++)
	{
		B[i] = A[i];  //复制左子向量
	}
	int lc = hi - mi;  //后子向量
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