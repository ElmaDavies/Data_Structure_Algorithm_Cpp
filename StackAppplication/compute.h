#pragma once

/*
�����沨�����ʽ����

*/
//float result; //����һ��ȫ�ֱ������������շ���ֵ

float compute(char* exp,int length)
{
	float a = 0; //��ʱ����������������ʱ������
	float b = 0;
	
	Stack<float> s; //����һ��ջ�����洢������
	length = length - 1;
	while (length>=0)
	{
		if (exp[length] >= '0' && exp[length] <= '9') {
			s.push((float)(exp[length]-48));


		}
		else if (exp[length] == '+')
		{
			a = (float)s.pop();
			b = (float)s.pop();
			s.push(a + b);
		}
		else if (exp[length] == '-')
		{
			a = (float)s.pop();
			b = (float)s.pop();
			s.push(a - b);
		}
		else if (exp[length] == '*')
		{
			a = (float)s.pop();
			b = (float)s.pop();
			s.push(a * b);
		}
		else if (exp[length] == '/')
		{
			a = (float)s.pop();
			b = (float)s.pop();
			s.push(a / b);
		}
		length--;
	}
	//result = s.top();
	return s.top();
}