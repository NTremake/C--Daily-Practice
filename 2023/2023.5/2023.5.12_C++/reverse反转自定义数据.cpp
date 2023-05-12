class Person {
public:
	Person(string name, int age) {
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};
void myPrint(Person& p) {
	cout << "姓名：" << p.m_name << "  年龄：" << p.m_age << endl;
}
void test01() {
	vector<Person> v1;
	for (int i = 0; i < 5; ++i) {
		int a = 1;
		string name = "张三";
		name += to_string(a += i);
		v1.push_back(Person(name, a = i + 20));
	}
	for_each(v1.begin(), v1.end(), myPrint);
	cout << "----------------------------" << endl;
	reverse(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;
}//reverse反转自定义数据
int main() {
	srand((unsigned int)time(NULL));
	test01();
	system("pause");
	return 0;
}