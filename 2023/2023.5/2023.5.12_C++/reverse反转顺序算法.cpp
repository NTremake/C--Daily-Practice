void myPrint(int val) {
	cout << val << "  ";
}
void test01() {
	vector<int> v1;
	for (int i = 0; i < 5; ++i) {
		v1.push_back(rand() % 5);
	}
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;
	reverse(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;
}//reverse反转算法
int main() {
	srand((unsigned int)time(NULL));
	test01();
	system("pause");
	return 0;
}