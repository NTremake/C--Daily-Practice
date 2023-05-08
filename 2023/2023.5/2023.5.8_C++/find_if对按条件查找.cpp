class Person{
public:
    Person(string name, int age){
        this->m_name = name;
        this->m_age = age;
    }
    bool operator()(const Person& p){
        return p.m_age > 20;
    }
    string m_name;
    int m_age;
};
class Greater20{
public:
    bool operator()(const Person& p){
        return p.m_age == 20;
    }
};
void test01(){
    vector<Person> v1;
    for(int i = 0; i < 10; ++i){
        Person p("张三", i+15);
        p.m_name += to_string(i+1);
        v1.push_back(p);
    }
    //vector<Person>::iterator it = find_if(v1.begin(), v1.end(), Person());
    vector<Person>::iterator it = find_if(v1.begin(), v1.end(), Greater20());
    if(it != v1.end()){
        cout << "找到了年龄为于20的人员，姓名：" << it->m_name << "  年龄：" << it->m_age << endl;
    }
    else{
        cout << "未找到年龄大于18的人员" << endl;
    }
}//find_if函数对自定义数据的查找
int main(){
    test01();
    system("pause");
    return 0;
}