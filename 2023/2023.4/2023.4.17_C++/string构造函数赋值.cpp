void test1(){
	string s1;//string本质上是一个类;默认构造
	const char* str = "hellow world!";
	string s2(str);//有参构造,string s(const char* s)
	cout << "s2 = " << s2 << endl;
	string s3(s2);//拷贝构造
	cout << "s3 = " << s3 << endl;
	string s4(5, 'a');//五个字符a初始化s4
	cout << "s4 = " << s4 << endl;
}
int main(){
	test1();
	system("pause");
	return 0;
}