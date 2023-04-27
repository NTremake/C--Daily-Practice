void test01() {
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	cout << "第一个数：" << &l1.front() << endl;
	cout << "最后一个数：" << &l1.back() << endl;
	list<int>::iterator it = l1.begin();
	cout << *(++it) << endl;//list链表只能用迭代器++或者--，不能跳跃式访问
}//list读取
int main(){
	test01();
	system("pause");
	return 0;
}