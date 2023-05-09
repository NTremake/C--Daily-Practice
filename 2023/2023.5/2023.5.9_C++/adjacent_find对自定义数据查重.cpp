class Person{
public:
    Person(string name, int age){
        this->m_name = name;
        this->m_age = age;
    }
    //重载==操作符,使得adjacent_find()对自定义数据类型也能查重
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
void myprint(vector<int>& v){
    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}
void test01(){
    vector<Person> v1;
    v1.push_back(Person("刘备", 35));
    v1.push_back(Person("关羽", 35));
    v1.push_back(Person("张飞", 35));
    v1.push_back(Person("张飞", 35));
    vector<Person>::iterator it = adjacent_find(v1.begin(), v1.end());
    if(it == v1.end()){
        cout << "没有找到相邻重复元素" << endl;
    }
    else{
        cout << "找到相邻重复元素：" << it->m_name << "  年龄：" << it->m_age << endl;
    }
}//adjacent_find()查找相邻重复元素，返回相邻元素的第一个位置的迭代器
int main(){
    test01();
    system("pause");
    return 0;
}