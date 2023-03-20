//typedef 重新定义类型名(int、float等），改名字；extern 引用另一个源文件的变量或函数；static 修饰全局变量时，会使变量只能作用于当前的源文件，不能被其他源文件引用，修饰函数时同理；
void test()
{
	static int a = 1;//static修饰局部变量时，使a不销毁，加入循环
	a++;
	printf("a=%d\n", a);
}
int main()
{
	int i=0;
	while (i < 5)
	{
		test();
		i++;
	}
	return 0;
  }//结果为a=2，a=3...a=6