void test1(){
	vector<int> v1;
	for (int i = 0; i < 10; ++i) {
		v1.push_back(i);
	}
	for (int i = 0; i < 10; ++i) {
		cout << v1[i] << "  ";
	}//下标的方式访问vector
	cout << endl;
	for (int i = 0; i < 10; ++i) {
		cout << v1.at(i) << "  ";
	}//at函数的方式访问
	cout << endl;
	cout << "第一个数为：" << v1.front() << endl;
	cout << "最后一个数为：" << v1.back() << endl;
}//访问vector
int main(){
	test1();
	system("pause");
	return 0;
}