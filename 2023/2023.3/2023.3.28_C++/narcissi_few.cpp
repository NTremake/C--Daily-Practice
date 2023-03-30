int main()//水仙花数(一个三位数，个十百位的数的三次方，的和等于这个三位数)
{
	int num=100;
	do
	{
		int a, b, c;
		a = num % 10;//个位
		b = num / 10 % 10;//十位
		c = num / 100 % 10;//百位
		if (a* a* a + b * b * b + c * c * c == num)
		{
			cout << num << "  ";
		}
		num++;
	} while (num < 1000);
	
	return 0;
}