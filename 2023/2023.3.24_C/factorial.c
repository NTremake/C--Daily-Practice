int Fac(int n)//求n的阶乘
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n * Fac(n - 1);
	}
}
int main()
{
	int n = 0;
	int ret = 0;
	scanf_s("%d", &n);
	ret = Fac(n);
	printf("%d\n", ret);
	return 0;
}