void printfList(const list<int>& L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); ++it) {
		cout << *it << "  ";
	}
	cout << endl;
}
void test01() {
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_front(3);
	L1.push_front(2);
	L1.push_front(1);
	printfList(L1);
	L1.pop_front();
	L1.pop_back();
	printfList(L1);
	list<int>::iterator it = L1.begin();
	L1.insert(++it, 200);//删除和插入只能使用迭代器
	L1.erase(L1.begin());
	printfList(L1);
	L1.insert(L1.begin(), 3, 3);
	printfList(L1);
	L1.remove(3);//删除所有3
	printfList(L1);
L1.insert(L1.begin(),L1.begin(),L1.end())//在begin位置插入一段区间的数据
}//list插入和删除
int main(){
	test01();
	system("pause");
	return 0;
}