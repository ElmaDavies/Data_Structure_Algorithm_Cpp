#pragma once
#include"queen.h"
Stack<Queen> placeQueens(int N)
{
	Stack<Queen> solu; //��Ž��ջ
	Queen q(0, 0);
	int nCheck = 0;
	int nSolu = 0;
	do {
		if (N <= solu.m_size || N <= q.y)  //���Ѿ����磬���ݵ���һ��
		{
			q = solu.pop();
			q.y++;
		}
		else
		{
			while ((q.y < N) && (0<solu.findElement(q))) //�ҵ����๥����Ԫ��
			{
				q.y++;     //������λ�ã����ҿ�ʼѰ����һ��
				nCheck++;
			}
			if (N > q.y)  
			{
				solu.push(q);   //��һ�е�λ���޷����๥����Ԫ����ջ
				if (N <= solu.m_size)
				{
					nSolu++;  //�ҵ��Ľ�
				}
				q.x++; //��ʼ��һ��
				q.y = 0;  //��һ�еĵ�һ�����¿�ʼ��
			}
		}
	
	} while ((0 < q.x) || (q.y < N));
	return solu;
}


