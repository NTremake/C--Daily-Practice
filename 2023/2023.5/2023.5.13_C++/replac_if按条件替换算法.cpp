void myPrint2(int val) {
	cout << val << "  ";
}
class ReplaceGreater2 {
public:
	bool operator()(int val) {
		return val >= 3;
	}
};
void test01() {
	vector<int> v1;
	for (int i = 0; i < 7; ++i) {
		v1.push_back(rand() % 6);
	}
	for_each(v1.begin(), v1.end(), myPrint2);
	cout << endl;
	replace_if(v1.begin(), v1.end(), ReplaceGreater2(), -1);
	for_each(v1.begin(), v1.end(), myPrint2);
	cout << endl;
}//replace_if按条件替换元素
int main() {
	srand((unsigned int)time(NULL));
	test01();
	system("pause");
	return 0;
}