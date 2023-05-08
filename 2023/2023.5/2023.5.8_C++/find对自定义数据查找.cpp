class Person{
public:
    Person(string name, int age){
        this->m_name = name;
        this->m_age = age;
    }
    //重载==号,让find知道如何对比Person数据类型
    bool operator==(const Person& p){
        if(this->m_name == p.m_name && this->m_age == p.m_age){
            return true;
        }
        else{
            return false;
        }
    }
    string m_name;
    int m_age;
};
void test01(){
    vector<Person> v1;
    for(int i = 0; i < 10; ++i){
        Person p("张三", i+15);
        p.m_name += to_string(i+1);
        v1.push_back(p);
    }
    Person p1("张三3", 17);
    //vector<Person>::iterator it = find(v1.begin(), v1.end(), Person("张三7", 21));
    vector<Person>::iterator it = find(v1.begin(), v1.end(), p1);
    if(it != v1.end()){
        cout << "找到了元素：" << endl;
        cout << "姓名：" << it->m_name << " 年龄：" << it->m_age << endl;
    }
    else{
        cout << "未找到元素" << endl;
    }
}//find函数对自定义数据的查找
int main(){
    test01();
    system("pause");
    return 0;
}