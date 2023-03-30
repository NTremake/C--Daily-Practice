int main()
{
	int a = 0;
	while(a<10)
	{
		a++;
		if (a == 5)
			continue;//跳过本次循环的后面部分；break是结束while循环的所有
		printf("%d ", a);
	}
	return 0;
}
--------------------------------------
int main()
{
	char ch=0;
	while((ch=getchar(ch)) != EOF)//getchar是获取输入的字符；EOF是end of file，值为-1，需要ctrl+z才能结束循环
	{
		putchar(ch);
	}
	return 0;
}
---------------------------------------
int main()
{
	char ch = 0;
	char password[20] = {0};
	int ret = 0;
	printf("请输入密码：");
	scanf_s("%s", password,20);//输入空格和回车会被误认为是结束密码输入，空格和回车之后的字符就会留在打印缓冲区，被后面的确认语句误读
	while ((ch=getchar()) != '\n')//直到接收到回车再结束循环；这个循环的目的是清除打印缓冲区的多余字符
	{
		;//空着，让while不断循环
	}
	printf("请确认（Y/N)：");
	ret = getchar();
	if (ret == 'Y')
	{
		printf("确认登录");
	}
	else
	{
		printf("放弃登录");
	}
	return 0;
}