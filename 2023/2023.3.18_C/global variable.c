int global = 2023;//全局变量，所有子函数都可以使用

void test()
{
	printf("test()-- %d\n", global);
}

int main()
 {
	int a=10;//局部变量，只能大括号内的函数使用
	test();
	printf("%d\n", global);
	return 0;
  }