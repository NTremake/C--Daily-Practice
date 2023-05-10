class Person{
public:
    Person(string name, int age){
        this->m_name = name;
        this->m_age = age;
    }
    bool operator()(const Person& p){
        if(p.m_age > 20){
            return true;
        }
        else{
            return false;
        }
    }
    string m_name;
    int m_age;
};
class Greater20{
public:
    bool operator()(const Person& p){
        if(p.m_age > 20){
            return true;
        }
        else{
            return false;
        }
    }
};
void test01(){
    vector<Person> v1;
    v1.push_back(Person("张三", 10));
    v1.push_back(Person("李四", 15));
    v1.push_back(Person("王五", 20));
    v1.push_back(Person("赵六", 25));
    v1.push_back(Person("刘七", 30));
    Person p1("钱八", 35);
    int num = count_if(v1.begin(), v1.end(), Person("钱八", 35));
    //int num = count_if(v1.begin(), v1.end(), Greater20());
    cout << "年龄大于20岁的人数为：" << num << endl;
}//count_if()函数可以自定义判断条件
int main(){
    test01();
    system("pause");
    return 0;
}