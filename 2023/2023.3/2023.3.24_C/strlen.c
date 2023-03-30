int my_strlen(char *str)
{
	int count=0;
	while(*str!='\0')
	{
		count++;
		str++;//地址向后移动一位
	}
	return count;
}
int main()//模拟strlen计算字符串大小的过程
{
	char arr[]="bit";
	int len=my_strlen(arr);//传的是首个字符的地址
	printf("len=%d\n",len);
	return 0;
}
-----------------------------------------------
int my_strlen(char *str)//不创建临时变量，使用递归的方法
{
	if(*str!='\0')
	{
		return 1+my_strlen(str+1);//使用运算符时，不能赋值，例如不能str++
	}
	else
	return 0;
}
int main()//模拟strlen计算字符串大小的过程
{
	char arr[]="bit";
	int len=my_strlen(arr);//数组传的是首个字符的地址
	printf("len=%d\n",len);
	return 0;
}