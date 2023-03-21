int main()//折半查找（二分查找）
{
	int arr1[] = {1,2,3,4,5,6,7,8};
	int k = 0;
	int n = sizeof(arr1) / sizeof(arr1[0]);//计算数组的总长度
	int left = 0;
	int right = n - 1;
	int mid =0;
	printf("请输入查找值：");
	scanf_s("%d", &k);
	while (left<=right)//折半查找适用于有序数组
	{
		mid = (left + right) / 2;
		if (k < arr1[mid]) 
		{
			right = mid - 1;
		}
		else if (k > arr1[mid])
		{
			left = mid + 1;
		}
		else
		{
			printf("查找值的下标为：%d\n", mid);
			break;
		}
	}
	if (left>right)
	{
		printf("未找到！");
	}
	return 0;
}