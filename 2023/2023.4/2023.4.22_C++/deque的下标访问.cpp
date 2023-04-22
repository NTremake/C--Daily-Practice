void test1(){
	deque<int>d1;
	d1.push_front(3);
	d1.push_front(2);
	d1.push_front(1);
	d1.push_back(4);
	d1.push_back(5);
	d1.push_back(6);
	for (int i = 0; i < 6; ++i) {
		cout << d1[i] << "  ";
	}
	cout << endl;
	for (int i = 0; i < 6; ++i) {
		cout << d1.at(i) << "  ";
	}
	cout << endl;
	cout << "front:" << d1.front() << endl;
	cout << "back:" << d1.back() << endl;
}//deque的遍历和读取
int main(){
	test1();
	system("pause");
	return 0;
}