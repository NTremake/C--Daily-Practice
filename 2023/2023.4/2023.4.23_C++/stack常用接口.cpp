void test01() {
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	cout << "stack的大小：" << s.size() << endl;
	while (!s.empty()) {
		cout << "栈顶元素：" << s.top() << endl;
		s.pop();
	}
	cout << "清空栈后的大小：" << s.size() << endl;
}//stack栈的常用接口
int main(){
	test01();
	system("pause");
	return 0;
}