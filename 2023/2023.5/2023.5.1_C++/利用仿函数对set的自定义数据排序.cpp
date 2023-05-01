class Person{
public://在类中重载()运算符，称为仿函数
    Person(string name,int age){
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};
class ComparePerson{
public:
    bool operator()(const Person& p1,const Person& p2)const{
        if(p1.m_Age == p2.m_Age){
            return p1.m_Name > p2.m_Name;
        }
        return p1.m_Age > p2.m_Age;
    }
};
void test01(){
    set<Person, ComparePerson> s1;
    Person p1("刘备", 35);
    Person p2("关羽", 33);
    Person p3("张飞", 31);
    Person p4("赵云", 32);
    Person p5("曹操", 32);
    s1.insert(p1);
    s1.insert(p2);
    s1.insert(p3);
    s1.insert(p4);
    s1.insert(p5);
    for(set<Person,ComparePerson>::iterator it = s1.begin();it!=s1.end();++it){
        cout << "姓名：" << (*it).m_Name << "  年龄：" << (*it).m_Age << endl;
    }
}//set对自定义数据类型的排序
int main(){
    test01();
    system("pause");
    return 0;
}