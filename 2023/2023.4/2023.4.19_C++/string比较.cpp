void test1(){
	string s1("hellow");
	string s2("hellow");
//compare函数是比较两个字符串是否相等，挨个比较每个字符的ASCII码值是否相等。s1小则返回-1;相等则返回0;s1大则返回1
	if (s1.compare(s2) == 0)
		cout << "字符串相等" << endl;
	else if (s1.compare(s2) == -1)
		cout << "s2字符串大" << endl;
	else
		cout << "s1字符串大" << endl;
}
int main(){
	test1();//字符串的比较
	system("pause");
	return 0;
}