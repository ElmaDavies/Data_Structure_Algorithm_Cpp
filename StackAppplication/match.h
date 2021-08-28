#pragma once
bool brackets_match(const char exp[], int lo, int hi)
{
	Stack<char> S;
	for (int i = lo; i <=hi; i++)
	{
		switch (exp[i])
		{
		case '(':
		case '[':
		case '{':
			S.push(exp[i]);
			break;
		case ')':
			if ((S.empty()) || (S.pop() != '('))
			{
				return false;
			}
			break;
		case ']':
			if ((S.empty()) || (S.pop() != '['))
			{
				return false;
			}
			break;
		case '}':
			if ((S.empty()) || (S.pop() != '{'))
			{
				return false;
			}
			break;
		}
	}
	return S.empty();  //ƥ����֮��ջ�л��������ţ���˵�����Ų�ƥ��
}