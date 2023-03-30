1、初始C++
#include <iostream>
using namespace std;

int main()
{
	cout << "Hello World!" << endl;//endl换行
system("pause");//最好加上这句，以查看控制台
	return 0;
}
---------------------------------------
int main()
{
	int week = 7;
	cout << "一周有:" << week << "天" << endl;//内容和变量分开打印
float a = 3.14f;//小数默认是双精度，把它定义成单精度会多一次转换，所以在小数后面加上f，直接告诉它是单精度
	cout << "a="<<a << endl;
	return 0;
}