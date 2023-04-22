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
	d1.push_front(1);
	d1.push_front(2);
	d1.push_front(3);
	d1.push_back(6);
	d1.push_back(5);
	d1.push_back(4);
	myprintf(d1);
	sort(d1.begin(), d1.end());
	myprintf(d1);
}//deque的sort排序算法
int main(){
	test1();
	system("pause");
	return 0;
}