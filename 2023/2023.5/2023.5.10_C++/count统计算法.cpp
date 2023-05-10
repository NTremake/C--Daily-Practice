class Person{
public:
    Person(string name, int age){
        this->m_name = name;
        this->m_age = age;
    }
    bool operator==(const Person& p){
        if(this->m_age == p.m_age){
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
    v1.push_back(Person("刘备", 35));
    v1.push_back(Person("关羽", 35));
    v1.push_back(Person("张飞", 35));
    v1.push_back(Person("赵云", 30));
    Person p1("曹操", 35);
    cout << "年龄为35岁的人数为：" << count(v1.begin(), v1.end(), p1) << endl;
}//count()计算元素个数
int main(){
    test01();
    system("pause");
    return 0;
}