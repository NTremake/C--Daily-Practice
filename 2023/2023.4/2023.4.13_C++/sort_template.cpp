template<class T>
void mySwap(T& arr1,T& arr2)
{
	T temp = arr1;
	arr1 = arr2;
	arr2 = temp;
}

template<class T>//选择排序模板的使用
void mySort(T& arr,int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if(max != i)
		{
			mySwap(arr[max], arr[i]);
		}
	}
}
template<class T>
void printfArray(T arr,int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << "   ";
	}
	cout << endl;
}
void test1()
{
	char charArr[] = "abcdef";
	int len = sizeof(charArr) / sizeof(char);
	mySort(charArr, len);
	printfArray(charArr, len);
}
void test2()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
	int len = sizeof(arr) / sizeof(int);
	mySort(arr, len);
	printfArray(arr, len);
}
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}