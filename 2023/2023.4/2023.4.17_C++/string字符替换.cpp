void test1(){
	string s1("1234321");
	int pos = s1.find('4');//find从左开始找
	cout << pos << endl;//返回字符串中的位置
	pos = s1.rfind('1');//rfind从右开始找
	cout << pos << endl;
	s1.replace(1, 2, "abc");//第一个位置开始，替换2个字符
	cout << s1 << endl;//替换为"abc"
}
int main(){
	test1();//find,rfind,replace三个函数
	system("pause");//string的查找和替换
	return 0;
}