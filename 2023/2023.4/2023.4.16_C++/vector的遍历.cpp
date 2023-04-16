void myPrintf(int val)
{
	cout << val << endl;
}
void test1()
{
	vector<int> v1;//创建一个vector容器，(数组模板)，需要<vector>头文件
	v1.push_back(10);//向容器中插入数据
	v1.push_back(11);
	v1.push_back(12);
	v1.push_back(13);
	//vector<int>::iterator itBegin = v1.begin();//起始迭代器，指向容器中的第一个元素
	//vector<int>::iterator itEnd = v1.end();//结束迭代器，指向容器中的最后一个元素的下一个位置
	//while (itBegin != itEnd) //第一种遍历方法
	//{
	//	cout << *itBegin << endl;//把itBegin当指针用
	//	itBegin++;
	//}
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{//第二种遍历方法
		cout << *it << endl;//it是指针
	}
	for_each(v1.begin(), v1.end(), myPrintf);//需要<algorithm>头文件
	//STL提供的遍历算法。起始位置，结束位置，自己创建的打印函数名
}//myprint是函数回调，把函数作为参数
int main()
{
	test1();
	system("pause");
	return 0;
}