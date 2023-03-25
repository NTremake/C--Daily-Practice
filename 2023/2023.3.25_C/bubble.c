void bubble(int arr[], int sz)//冒泡排序
{
	int i = 0;
	for (i = 1; i < sz; i++)//需要n-1趟排序
	{
int flag=1;//每遍历一趟，就假设数列是从小到大有序的
		int j = 0;//每趟需要比较n-i次，每趟减少一次比较
		for (j = 0; j < sz - i; j++)
{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
flag=0;//只要运行过if就不是有序
			}
		}
if(falg==1)//当数列没有交换过时，那就是有序的，直接结束循环
{
break;
}
	}
}
int main()
{
	int arr[] = { 5,8,17,6,11,4,3,12,1,0 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}