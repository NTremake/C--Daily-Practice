class Person{
public:
    Person(string name, int age){
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
};
class myPrint17{
public:
    void operator()(const Person& p){
        if(p.m_age > 17){
            cout << "姓名：" << left << setw(7) << p.m_name << "  年龄：" << p.m_age << endl;
        }
    }
};
void test01(){
    vector<Person> v1;
    for(int i = 0; i < 10; ++i){
        Person p("张三", i+15);
        p.m_name += to_string(i+1);
        v1.push_back(p);
    }
    for_each(v1.begin(), v1.end(), myPrint17());
}//for_each函数对自定义数据的遍历
int main(){
    test01();
    system("pause");
    return 0;
}