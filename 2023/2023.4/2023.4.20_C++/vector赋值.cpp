void myprintf(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
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
	vector<int> v2;
	v2 = v1;//vector& operator=(vector& vec)
	myprintf(v2);
	vector<int> v3;
	v3.assign(v1.begin(), v1.end());
	myprintf(v3);
	v3.assign(3, 1);
	myprintf(v3);
}//vector的赋值
int main(){
	test1();
	system("pause");
	return 0;
}