int Fib(int n)//计算斐波那契数列
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)//这种就不适合用递归，会跑满二叉树，效率低
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main()
{
	int n = 0;
	int ret = 0;
	scanf_s("%d", &n);
	ret = Fib(n);
	printf("%d\n", ret);
	return 0;
}