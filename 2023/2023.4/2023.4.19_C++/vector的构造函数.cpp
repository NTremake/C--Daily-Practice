Vector是动态数组，插入数据时，开辟新空间再删除旧空间
void myprintf(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}
void test1(){
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	myprintf(v1);
	vector<int> v2(v1.begin(), v1.end());
	myprintf(v2);//利用vector首尾区间构造新的
	vector<int> v3(10, 8);//10个8
	myprintf(v3);
	vector<int> v4(v1);
	myprintf(v4);
}//vector的构造
int main(){
	test1();
	system("pause");
	return 0;
}