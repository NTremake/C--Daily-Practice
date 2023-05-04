class Person{
public:
    Person(int id, int age){
        this->m_Id = id;
        this->m_Age = age;
    }
    int m_Id;
    int m_Age;
};
class myCompare{
public:
    bool operator()(const Person& p1, const Person& p2)const{//自定义数据的运算符重载，要加const
        //return p1.m_Id < p2.m_Id;
        return p1.m_Id > p2.m_Id;
    }
};
void printMap(const map<Person, string, myCompare>& m){
    for(map<Person, string, myCompare>::const_iterator it = m.begin(); it != m.end(); ++it){
        cout << "id：" << (it->first).m_Id << "  姓名：" << it->second << "  年纪：" << (it->first).m_Age << endl;
    }
    cout << endl;
}
void test01(){
    map<Person, string, myCompare> m1;
    Person pArray[6]={Person(1, 11), Person(2, 22), Person(3, 33), Person(4, 44), Person(5, 55), Person(6, 66)};//Person做成数组，方便循环插入
    for(int i=0; i<6; ++i){
        string name = "name" + to_string(i+1);//to_string()将int转换为string
        //Person p(i+1, (i+1)*11);
        m1.insert(make_pair(pArray[i], name));
    }
    printMap(m1);
}//map容器
int main(){
    test01();
    system("pause");
    return 0;
}