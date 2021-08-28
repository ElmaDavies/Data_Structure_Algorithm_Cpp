void convert(Stack<char>& s, int n, int base)
{
	char digit[] = { '0' ,'1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	if (0 < n)
	{
		convert(s, n / base, base);
		s.push(digit[n % base]);
	}
}


