#pragma once
/*
*
*  �沨������ʽ����׺����ʽ
*  ��׺����ʽ�� ��1+2��*3+4
*  ��׺����ʽ��  12+3*4+
* ��ջʵ�֣� ���裺1>��������ջ��S1��S2��S1���������������S2�������洦������
* 
*
*/

//��������ȫ�ֱ������������շ��ص��ַ���
int length=0; //��¼�ַ������ȣ��������
char returnStr[256]; //��¼�ַ���
void RPN(char* express)
{
	Stack<char> s1;
	Stack<char> s2;
	  //���ص�����
	char* p = express;
	char c; //��ʱ���������ڼ�¼ջ�е�����Ԫ��
	//length = 0;
	s1.push('#');  //Ĭ��#��������ȼ��������
	while (*p != '\0')
	{
	
		if(*p=='(')  //������ֱ�Ӵ���s1ջ��
		{
			s1.push(*p);
		
		}
		else if (*p == ')')  //������ƥ������ģ���������ЩԪ��ȫ������ջs2��
		{ 
			
			while (s1.top() != '(')
			{
				
				s2.push(s1.pop());
				
			}
			s1.pop();  //�ǵ�������ջ��'('����
		}
		else if (*p >= '0' && *p <= '9') //������ȫ������ջS2��
		{
			s2.push(*p);
			
			
		}
		else if (*p == '+' || *p == '-') //
		{
			/*
			//�������������ȼ�С��s1ջ��Ԫ�أ���s1
			��ջ��Ԫ�ص���������s2ջ��,ֱ��s1��ջ����������ڸ�����������ȼ�
			*/
			
			if (s1.top() == '*' || s1.top()=='/')	        //С��s1��ջ��Ԫ��                        
			{
				                            //��s1��ջ��Ԫ��ȫ������������s2��
				                            //ֱ��s1��ջ�������С�ڸ������
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
		�������������ڻ��ߵ���S1ջ������������ȼ�������
		ѹ��s1��ջ��
		
		
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

	
	//ջ������
	while (!s2.empty())
	{
		returnStr[length++] = s2.pop();
		
		
	}
	//std::cout << length << std::endl;

	
}