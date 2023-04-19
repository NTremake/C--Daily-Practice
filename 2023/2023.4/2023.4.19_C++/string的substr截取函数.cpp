void test1(){
	string email = "zhangsan@qq.com";
	int pos = email.find('@');//查找@的下标
	string name = email.substr(0, pos);//截取字符串，起始下标->结束下标
	cout << name << endl;
}
int main(){
	test1();
	system("pause");
	return 0;
}