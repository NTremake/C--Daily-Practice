#include <iostream>
using namespace std;
#include <iomanip>

int Max(int a, int b){
	return  a > b ? a : b;
}
int Min(int a, int b){
	return a < b ? a : b;
}
int Sum(int a, int b){
	return a + b;
}
void PrintData(int (*p)(int, int), int a, int b){
	cout << p(a, b) << endl;
}
int main() {
	/*int a = 1, b = 2;
	int(*p)(int, int) = nullptr;
	p = sum;
	cout << p(a, b) << endl;*/
	void (*printData)(int (*)(int, int), int, int) = PrintData;
	printData(Max, 1, 2);
	printData(Min, 1, 2);
	printData(Sum, 1, 2);
	//���ú���ָ����Ϊ��������������ʵ�ֺ����Ļص���C++�Ķ�̬����

	system("pause");
	return 0;
}