void test1(){
	string s1 = "hellow world!";//string& operator=(const char* str)
	cout << "s1 = " << s1 << endl;
	string s2 = s1;//string& operator=(const string& str)
	cout << "s2 = " << s2 << endl;
	string s3;
	s3 = 'a';//string& operator=(const char c)
	cout << "s3 = " << s3 << endl;
	string s4;
	s4.assign("hellow world!");//string& assign(const char* str)
	cout << "s4 = " << s4 << endl;
	string s5;//string& assign(const char* str, int a)
	s5.assign("hellow world!", 6);//把字符串的前六个字符给s5
	cout << "s5 = " << s5 << endl;
	string s6;
	s6.assign(s5);//string& assign(const string& s)
	cout << "s6 = " << s6 << endl;
	string s7;
	s7.assign(5, 'a');//string& assign(int a,char c)
	cout << "s7 = " << s7 << endl;//5个字符a初始化s7

}//string的=号重载，assign函数赋值
int main(){
	test1();//string字符串赋值操作
	system("pause");
	return 0;
}