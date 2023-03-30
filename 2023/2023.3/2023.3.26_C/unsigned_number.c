int main()
{
	int a = -128;//补码->在忽略首位符号打印补码
	printf("%u\n",a);//打印无符号十进制数
	return 0;//4294967168
}
-----------------------------------------
int main()//有符号和无符号数计算，直接用补码计算
{
	int a = -20;
	unsigned int b = 10;
	printf("%d\n", a + b);
	return 0;
}
--------------------------------------
int main()
{
	unsigned int a = 0;
	for (a = 9; a >= 0; a--)
	{
		printf("%u\n", a);//死循环,当a=-1时，打印%u会导致a变为正数
		Sleep(200);
	}
	return 0;
}