int main()
 {
	int line = 0;
	printf("进入B站大学！");

	while(line<2000)//函数后面不加分号，while循环函数用大括号包住
	{
		printf("敲一行代码!:%d\n",line);
		line++;
	}
	if(line>=2000)
		printf("找到一份好工作！\n");
	return 0;
  }
------------------------------------------
int Add(int x, int y)//自己定义函数，方便重复函数的调用
{
	int z =  x +  y;
	return  z;
}
int main()
 {
	int a = 0;
	int b = 0;
	int sum = 0;
	scanf_s("%d%d", &a, &b);
	sum = Add(a, b);
	printf("sum=%d\n", sum);
	return 0;
  }