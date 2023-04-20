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
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	myprintf(v1);
	v1.insert(v1.begin(), 666);//首地址前插入一个666
	myprintf(v1);
	v1.insert(v1.begin(), 2, 555);//首地址前插入2个555
	myprintf(v1);
	v1.erase(v1.begin());//删除首地址的数
	myprintf(v1);
	/*v1.erase(v1.begin(),v1.end());*/
	v1.clear();//清空vector
	myprintf(v1);
}//vector的插入和删除
int main(){
	test1();
	system("pause");
	return 0;
}