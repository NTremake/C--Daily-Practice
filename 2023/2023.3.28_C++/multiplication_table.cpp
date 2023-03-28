int main()//九九乘法表
{
	int i;
	for (i = 1; i <= 9; i++)
	{
		int j;
		for (j = 1; j <= i; j++)
		{
			cout << j << "*" << i << "=" << std::left << setw(2) << j * i << "  ";
		}//setw(2)用空格占位2个，有字符则不输出空格输出字符；默认是右对齐，用std::left设置为左对齐；都需要头文件<iomanip>。
		cout << endl<<endl;
	}
	return 0;
}