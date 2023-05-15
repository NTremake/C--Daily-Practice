void myPrint2(int val) {
	cout << left << setw(4) << val;
}
void test01() {
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 7; ++i) {
		v1.push_back(i);
		v2.push_back(i + 10);
	}
	v2.pop_back();
	for_each(v1.begin(), v1.end(), myPrint2);
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint2);
	cout << endl;
	cout << "交换后---------------------" << endl;
	swap(v1, v2);
	for_each(v1.begin(), v1.end(), myPrint2);
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint2);
	cout << endl;
}//swap容器交换
int main() {
	srand((unsigned int)time(NULL));
	test01();
	system("pause");
	return 0;
}