int main()
{
	int a ;
	scanf_s("%d", &a);
	switch (a)//switch函数是整形函数，只能判断整形
	{
	case 1://case里面可以嵌套switch等
语句
		printf("星期一\n");
		break;//没有break打断的话，会
继续执行后面的条件
	case 2:
		printf("星期2\n");
		break;
	case 3:
		printf("星期3\n");
		break;
	case 4:
		printf("星期4\n");
		break;
	case 5:
		printf("星期5\n");
		break;
	case 6:
		printf("星期6\n");
		break;
	case 7:
		printf("休息日\n");
		break;
	default:
		printf("输入错误！\n");//其他乱七八糟的情况用default语句
	   break;
	}
	return 0;
}
------------------------------------------------------------
int main()
{
	int a ;
	scanf_s("%d", &a);
	switch (a)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("工作日\n");
		break;
	case 6:
	case 7:
		printf("休息日\n");
		break;
	}
	return 0;
}