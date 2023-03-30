int main()
{
	int i = 0;
	for (i = 1; i <= 10; i++)//初始化；条件；完成一次循环后调整
	{
		printf("%d ", i);
	}
	return 0;
}
-----------------------------------
int main()
{
	int i = 0;
	do//do while结构，是先执行，再判断条件
	{
		printf("%d ", i);
		i++;
	}
	while(i <= 10);//while后面有分号，结束该函数
	return 0;
}