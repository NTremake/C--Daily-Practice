printf("%d",printf("%d",printf("%d",43)));//链式访问，将一个函数的返回值，作为另一个函数的参数。
-----------------------------
#ifndef__ADD_H__//if not define,就能够引用函数；如果定义了，就结束，不会重复引用
#define __ADD_H__
int Add(int x,int y);
#endif
------------------------------------------
void print(int n)//函数的递归，自己调用自己
{
	if(n>9)
	{
		print(n/10);//n除以10后，再次调用函数；每次递归需要条件，不然可能死循环;
	}
	printf("%d ",n%10);
}
int main()
{
	unsigned int a=0;
	scanf("%d",&a);
	print(a);
	return 0;
}