void myprintf(deque<int>& v)
{
	for (deque<int>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		/**it = 100;*///静态指针
		cout << *it << "  ";
	}
	cout << endl;
}
void test1(){
	deque<int>d1;
	for (int i = 0; i < 10; ++ i) {
		d1.push_back(i);
	}
	myprintf(d1);
	deque<int>d2(d1.begin(), d1.end());
d2 = d1;
	myprintf(d2);
	deque<int>d3(10, 66);
	myprintf(d3);
	deque<int>d4(d3);
	myprintf(d4);
}//deque的构造函数
int main(){
	test1();
	system("pause");
	return 0;
}