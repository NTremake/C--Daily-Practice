void myPrint2(int val) {
	cout << val << "  ";
}
void test01() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(10);
	for_each(v1.begin(), v1.end(), myPrint2);
	cout << endl;
	replace(v1.begin(), v1.end(), 10, 66);//将10替换成66
	for_each(v1.begin(), v1.end(), myPrint2);
	cout << endl;
}//replace替换元素
int main() {
	test01();
	system("pause");
	return 0;
}