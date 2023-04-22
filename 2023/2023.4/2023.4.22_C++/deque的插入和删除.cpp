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
	d1.push_back(10);
	d1.insert(d1.begin(), 2, 22);
	myprintf(d1);
	d1.insert(d1.begin(), d1.begin(), d1.end());//pos,first,end
	myprintf(d1);
	d1.erase(d1.begin());//不能直接运算，需要迭代器接收地址
	deque<int>::iterator it = d1.begin();
	it += 4;//指针偏移
	d1.erase(it);
	myprintf(d1);
}//deque的插入删除
int main(){
	test1();
	system("pause");
	return 0;
}