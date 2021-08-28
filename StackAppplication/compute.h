#pragma once

/*
利用逆波兰表达式计算

*/
//float result; //定义一个全局变量，用来接收返回值

float compute(char* exp,int length)
{
	float a = 0; //临时变量，用来保存临时计算结果
	float b = 0;
	
	Stack<float> s; //定义一个栈用来存储计算结果
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