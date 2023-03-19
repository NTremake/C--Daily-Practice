int main()
 {
	char arr1[] = "abc";//字符串后面有一个隐藏的\0，作为结束标志，不算字符内容
	char arr2[] = { 'a','b','c',0 };//这个0不算字符内容
	printf("%s\n", arr1);
	printf("%s\n", arr2);
	return 0;
  }
--------------------------------
int main()
 {
	char arr1[] = "abc";
	char arr2[] = { 'a','b','c' };
	printf("%d\n", strlen(arr1));//打印字符串长度，arr1=3；arr2=随机，如果结尾加上0，也是3
	printf("%d\n", strlen(arr2));
	return 0;
  }