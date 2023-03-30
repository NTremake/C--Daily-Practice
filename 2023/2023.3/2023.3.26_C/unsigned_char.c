int main()
{
	char a[1000];
	int i = 0;
	for (i = 0; i <1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d\n", strlen(a));//a是char类型，所以a里面的数值是-128~127，然后strlen是计算到\0时停止，所以有255个字符
	return 0;
}
------------------------------------
int main()
{
	unsigned char i=0;
	for (i = 0; i <256; i++)//256超出了i的数值范围，会死循环
	{
		printf("haha\n");
	}
	return 0;
}