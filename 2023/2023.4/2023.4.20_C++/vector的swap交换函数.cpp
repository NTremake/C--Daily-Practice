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
	for (int i = 0; i < 10; ++i) {
		v1.push_back(i);
	}
	myprintf(v1);
	vector<int> v2;
	for (int i = 9; i > -1; --i) {
		v2.push_back(i);
	}
	myprintf(v2);
	v1.swap(v2);//vector的交换
	myprintf(v1);
	myprintf(v2);
}
void test02() {
	vector<int> v1;
	for (int i = 0; i < 1000; ++i) {
		v1.push_back(i);
	}
	cout << "v1的容量：" << v1.capacity() << endl;
	cout << "v1的大小：" << v1.size() << endl;
	v1.resize(10);//并不能改变v1的容量，所以会浪费内存
	cout << "v1的容量：" << v1.capacity() << endl;
	cout << "v1的大小：" << v1.size() << endl;
	/*vector<int>(v1)*///把v1拷贝给匿名对象
	vector<int>(v1).swap(v1);//匿名对象拷贝后，容积就会变正常，然后和v1交换
	cout << "v1的容量：" << v1.capacity() << endl;
	cout << "v1的大小：" << v1.size() << endl;
}//拷贝匿名对象来交换，以收缩vector内存
int main(){
	/*test1();*/
	test02();
	system("pause");
	return 0;
}