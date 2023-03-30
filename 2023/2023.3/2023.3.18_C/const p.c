int main()
{
	const int num1 = 1;
	//num1 = 2;错误，不能被修改
	int num2 = 2;
	const int* p = &num2;
	//*p = 1;错误，不能被修改
	return 0;
}