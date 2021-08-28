#pragma once
#include"queen.h"
Stack<Queen> placeQueens(int N)
{
	Stack<Queen> solu; //存放解的栈
	Queen q(0, 0);
	int nCheck = 0;
	int nSolu = 0;
	do {
		if (N <= solu.m_size || N <= q.y)  //若已经出界，回溯到上一行
		{
			q = solu.pop();
			q.y++;
		}
		else
		{
			while ((q.y < N) && (0<solu.findElement(q))) //找到互相攻击的元素
			{
				q.y++;     //标记这个位置，并且开始寻找下一列
				nCheck++;
			}
			if (N > q.y)  
			{
				solu.push(q);   //下一列的位置无法互相攻击的元素入栈
				if (N <= solu.m_size)
				{
					nSolu++;  //找到的解
				}
				q.x++; //开始下一行
				q.y = 0;  //下一行的第一列重新开始找
			}
		}
	
	} while ((0 < q.x) || (q.y < N));
	return solu;
}


