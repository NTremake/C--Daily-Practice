void myPrint(int val) {
	cout << val << " ";
}
void test01() {
	vector<int> v1;
	vector<int> v2;//两个容器必须是升序有序序列
	for (int i = 0; i < 10; ++i) {
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	vector<int> vTarget;
	vTarget.resize(v1.size() + v2.size());//目标容器要预先开辟空间
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), myPrint);
	cout << endl;
}//merge合并两个有序链表
int main() {
	test01();
	system("pause");
	return 0;
}