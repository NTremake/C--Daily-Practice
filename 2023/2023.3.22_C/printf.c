#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>

int main()
{
	char arr1[] = "Welcome to MianYang!";
	char arr2[] = "********************";
	int left = 0;
	int right = strlen(arr1) - 1;//计算字符串最后一个下标，需要<String.h>库函数
	while (left < right)
	{
		arr2[left] = arr1[left];//因为两个字符串长度一样，所有下标可以一一对应
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		Sleep(1000);//延迟一秒，需要<Windows.h>库函数
		system("cls");//执行系统命令，清空(控制台)屏幕，需要<Stdlib.h>库函数
		left++; 
		right--;
	}

	return 0;
}