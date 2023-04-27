void printfList(const list<int>& L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); ++it) {
		cout << *it << "  ";
	}
	cout << endl;
}
bool myCompare(int a, int b) {
	return a > b;//a>b为假，变降序
}
void test01() {
	list<int> l1;
	l1.push_back(1);
	l1.push_back(3);
	l1.push_back(2);
	l1.push_back(5);
	l1.push_back(4);
//list链表不能用标准算法sort排序，只能使用list的成员函数sort
	l1.sort();//升序排列
	printfList(l1);
	l1.sort(myCompare);//利用myCompare变降序
	printfList(l1);
	l1.reverse();//反转链表的函数
	printfList(l1);
}//list排序
int main(){
	test01();
	system("pause");
	return 0;
}