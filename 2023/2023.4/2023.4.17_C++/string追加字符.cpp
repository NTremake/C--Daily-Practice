void test1(){
	string s1 = "I Love";//string& operator+=(const char* str)
	s1 += " You";
	cout << "s1 = " << s1 << endl;

	s1 += '.';//string& operator=(const char c)
	cout << "s1 = " << s1 << endl;

	string s2;//string& operator+=(const string& str)
	s2 += s1;
	cout << "s2 = " << s2 << endl;

	string s3 = "And";
	s3.append(" You");//string& append(const char* str)
	cout << "s3 = " << s3 << endl;

	s3.append("?aaa", 1);//string& append(const char* str, int a)
	cout << "s3 = " << s3 << endl;

	s3.append(s2);//string& append(const string& str)
	cout << "s3 = " << s3 << endl;

	string s4;
	s4.append(s1, 2, 4);//string& append(const string& str,int pos,int a)
	cout << "s4 = " << s4 << endl;//从s1[pos]开始，追加2个字符
}//string字符串拼接、追加操作;append追加字符函数
int main(){
	test1();
	system("pause");
	return 0;
}