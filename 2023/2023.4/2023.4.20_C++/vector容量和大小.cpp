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
	for (int i = 0; i < 10; i++){
		v1.push_back(i);
	}
	myprintf(v1);
	if(v1.empty()){
		cout << "vector为空" << endl;
	}//empty函数返回bool变量，true为空
	else {
		cout << "vector不为空" << endl;
		cout << "vector容量为：" << v1.capacity() << endl;
		cout << "vector大小为：" << v1.size() << endl;
	}
	/*v1.resize(15);*///默认新的数为0
	v1.resize(15, 100);//重新指定大小为15，初始化为100
	myprintf(v1);
	v1.resize(5);
	myprintf(v1);
}//vector的容量和大小
int main(){
	test1();
	system("pause");
	return 0;
}