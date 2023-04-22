void test1(){
	vector<int> v1;
	v1.reserve(10000);//直接预留10000的空间，不会赋值
	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 10000; ++i) {
		v1.push_back(i);
		if (p != &v1[0]) {
			p = &v1[0];//p地址不等于vector首地址，则说明新开辟过空间
			num++;
		}//检测在赋值过程中开辟了多少次空间
	}
	cout << num << endl;
}//vector的预留空间reserve函数
int main(){
	test1();
	system("pause");
	return 0;
}