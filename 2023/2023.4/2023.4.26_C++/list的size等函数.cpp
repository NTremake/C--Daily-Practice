void printList(const list<int>& L1) {
	for (list<int>::const_iterator it = L1.begin(); it != L1.end(); ++it) {
		cout << *it << "  ";
	}
	cout << endl;
}
void test01() {
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);
	if (L1.empty()) {
		cout << "L1为空" << endl;
	}
	else {
		cout << "L1不为空" << endl;
		cout << "L1的大小为：" << L1.size() << endl;
	}
	L1.resize(6, 100);//重新指定大小为6，用100补充
	printList(L1);
	L1.resize(2);
	printList(L1);
}//list的empty、size和resize函数
int main(){
	test01();
	system("pause");
	return 0;
}