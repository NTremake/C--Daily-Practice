void myPrint2(int val) {
	cout << val << "  ";
}
void test01() {
	vector<int> v1;
	for (int i = 0; i < 8; ++i) {
		v1.push_back(i);
	}
	for_each(v1.begin(), v1.end(), myPrint2);
	cout << endl;
	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), myPrint2);
	cout << endl;
}//copy拷贝函数，需要预先开辟空间
int main() {
	srand((unsigned int)time(NULL));
	test01();
	system("pause");
	return 0;
}