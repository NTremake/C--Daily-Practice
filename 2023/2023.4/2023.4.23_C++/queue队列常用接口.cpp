class Person
{
public:
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
void test01() {
	queue<Person>q1;
	Person p1("张三", 18);
	Person p2("李四", 19);
	Person p3("王五", 20);
	Person p4("赵六", 21);
	q1.push(p1);
	q1.push(p2);
	q1.push(p3);
	q1.push(p4);
	while (!q1.empty()) {
		cout << "队头人员姓名：" << q1.front().m_Name << "  年龄：" << q1.front().m_Age << endl;
		q1.pop();
	}
	cout << "队列的大小：" << q1.size() << endl;
}//queue队列常用接口
int main(){
	test01();
	system("pause");
	return 0;
}