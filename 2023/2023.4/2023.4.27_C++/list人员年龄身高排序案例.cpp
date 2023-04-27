class Person
{
public:
	Person(string name, int age, int height) {
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}
	string m_Name;
	int m_Age;
	int m_Height;
};
void myPrint(list<Person>& L) {
	for (list<Person>::iterator it = L.begin(); it != L.end(); ++it) {
		cout << "姓名：" << it->m_Name << "  年龄：" << it->m_Age << "  身高：" << it->m_Height << endl;
	}
}
bool comparePerson(Person& p1, Person& p2) {
	if (p1.m_Age == p2.m_Age) {
		return p1.m_Height > p2.m_Height;
	}//年龄相等，再判断身高
	return p1.m_Age < p2.m_Age;
}
void test01() {
	list<Person> L;
	Person p1("张三", 24, 174);
	Person p2("李四", 21, 171);
	Person p3("王五", 23, 173);
	Person p4("赵六", 24, 173);
	Person p5("刘七", 22, 172);
	Person p6("张力", 24, 175);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	myPrint(L);
	cout << "排序后------------------------" << endl;
	L.sort(comparePerson);//不能直接判断自定义数据类型
	myPrint(L);
}//list排序案例
int main(){
	test01();
	system("pause");
	return 0;
}