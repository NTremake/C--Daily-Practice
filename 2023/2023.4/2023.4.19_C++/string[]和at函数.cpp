void test1(){
	string s1("hellow");
	for (int i = 0; i < s1.size(); i++){
		cout << s1[i] << " ";
	}//char& operator[](int n)
	cout << endl;
	for (int i = 0; i < s1.size(); i++){
		cout << s1.at(i) << " ";
	}
	cout << endl;
	s1[0] = 'x';
	cout << s1 << endl;
	s1.at(1) = 'x';
	cout << s1 << endl;
}
int main(){
	test1();//数组方式和at函数对字符串的存取
	system("pause");
	return 0;
}