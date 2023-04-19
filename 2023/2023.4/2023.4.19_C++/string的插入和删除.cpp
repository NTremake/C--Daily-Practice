void test1(){
	string s1("hellow");
	s1.insert(1, "222");//s1[1]前面插入
	cout << s1 << endl;//insert(1,3,'2')
	s1.erase(1, 3);//s1[1]开始，删除三个字符
	cout << s1 << endl;
}
int main(){
	test1();
	system("pause");
	return 0;
}