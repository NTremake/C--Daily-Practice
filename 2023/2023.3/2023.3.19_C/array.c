int main()
 {
	int i = 0;
	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };//定义一个数组，10代表最多存放是个数
	while(i<10)
	{
		printf("%d\n", arr[i]);//[]用下标顺序，打印数组中的数
		i++;
	}
	return 0;
  }