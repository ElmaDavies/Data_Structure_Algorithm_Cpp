#pragma once
/*
*
*  逆波兰表达式，后缀表达式
*  中缀表达式： （1+2）*3+4
*  后缀表达式：  12+3*4+
* 用栈实现： 步骤：1>定义两个栈，S1和S2，S1用来保存运算符，S2用来保存处理操作
* 
*
*/

//定义两个全局变量，用来接收返回的字符串
int length=0; //记录字符串长度，便于输出
char returnStr[256]; //记录字符串
void RPN(char* express)
{
	Stack<char> s1;
	Stack<char> s2;
	  //返回的内容
	char* p = express;
	char c; //临时变量，用于记录栈中弹出的元素
	//length = 0;
	s1.push('#');  //默认#是最低优先级的运算符
	while (*p != '\0')
	{
	
		if(*p=='(')  //遇到（直接存入s1栈中
		{
			s1.push(*p);
		
		}
		else if (*p == ')')  //遇到）匹配最近的（，并将这些元素全部放入栈s2中
		{ 
			
			while (s1.top() != '(')
			{
				
				s2.push(s1.pop());
				
			}
			s1.pop();  //记得抛弃入栈的'('符号
		}
		else if (*p >= '0' && *p <= '9') //操作数全部放入栈S2中
		{
			s2.push(*p);
			
			
		}
		else if (*p == '+' || *p == '-') //
		{
			/*
			//如果该运算符优先级小于s1栈顶元素，则将s1
			的栈顶元素弹出，送入s2栈中,直至s1的栈顶运算符低于该运算符的优先级
			*/
			
			if (s1.top() == '*' || s1.top()=='/')	        //小于s1的栈顶元素                        
			{
				                            //将s1的栈顶元素全部弹出，放入s2中
				                            //直到s1的栈顶运算符小于该运算符
				while (s1.top()!='#' )
				{
					if (s1.top() == '(')
					{
						break;
					}
					else
					{
						
						s2.push(s1.pop());
						
					}
					
				}
			}
			s1.push(*p);
			
			
		}
		/*
		如果该运算符大于或者等于S1栈顶的运算符优先级，将其
		压入s1的栈中
		
		
		*/
		else if (*p == '*' || *p == '/')
		{
			c = s1.top();
			
			if (c == '(')
			{
				break;
			}
			else
			{
				s1.push(*p);
			}
			
				
			

		}
		

		p++;
	}

	while (s1.top()!='#')
	{
		s2.push(s1.pop());
	}

	
	//栈中逆序
	while (!s2.empty())
	{
		returnStr[length++] = s2.pop();
		
		
	}
	//std::cout << length << std::endl;

	
}