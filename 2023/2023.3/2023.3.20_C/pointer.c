int main()//数组中两元素中间元素个数的计算
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("%d\n", &a[8] - &a[0]);//计算1~9中间的元素个数，8个
	return 0;
}
---------------------------------------
int main()//区分首元素地址和数组地址
{
	int a[10] = { 0 };
	printf("%p\n", a);//首元素地址
	printf("%p\n", a+1);
	printf("%p\n", &a[0]);//首元素地址
	printf("%p\n", &a[0] + 1);
	printf("%p\n", &a);//整个数组的地址
	printf("%p\n", &a+1);
	return 0;
}
------------------------------------
int main()
{
	int a = 1;
	int* p = &a;
	int** pa = &p;//二级指针
	**pa = 10;
	printf("%d\n", **pa);
	return 0;
}
-----------------------------------
int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int i = 0;
	int* arr[3] = { &a,&b,&c };//指针数组，存放多个指针
	for (i = 0; i < 3; i++)
	{
		printf("%d  ", *(arr[i]));
	}
	return 0;
}
-----------------------------------------
void my_strcpy(char* dest,const char* src)//模拟strcpy函数;const常属性，不能放在等号左边被修改
{
	assert(dest != NULL);//assert断言：指出报错的文件，需要assert.h头文件
	assert(src != NULL);
	while (*src!='\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';//复制完bit就停止，不然会打印出arr1剩余字符
}
int main()
{
	char arr1[] = "#####";
	char arr2[] = "bit";
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}