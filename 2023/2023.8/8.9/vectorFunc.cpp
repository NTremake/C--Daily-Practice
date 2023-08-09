//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Person {
//public:
//    Person() {
//        cout << "默认构造函数" << endl;
//    }
//    Person(string name) : name(name) {
//        cout << "有参构造函数：" << this->name << endl;
//    }
//    Person(const Person& p) : name(p.name) {
//        cout << "拷贝构造函数：" << this->name << endl;
//    }
//    Person operator=(const Person& p) {
//        cout << "赋值运算符重载：" << this->name << endl;
//        return *this;
//    }
//    ~Person() {
//        cout << "析构函数：" << this->name << endl;
//    }
//    string name;
//};
//int main() {
//    vector<Person> v;
//    v.emplace_back("张三");
//    cout << "1Capacity = " << v.capacity() << endl;
//    v.emplace_back("李四");
//    cout << "2Capacity = " << v.capacity() << endl;
//    v.emplace_back("王五");
//    cout << "3Capacity = " << v.capacity() << endl;
//    cout << "------------------" << endl;
//    /*for (auto a : v) {
//        cout << a.name << "  " << endl;
//    }*/
//    for (const auto& a : v) {
//        cout << a.name << "  " << endl;
//    }//这里用引用，就不会调用拷贝构造函数和析构函数
//    cout << "------------------" << endl;
//    for (vector<Person>::iterator it = v.begin(); it != v.end(); ++it) {
//		cout << (*it).name << "  " << endl;
//	}//其实直接使用迭代器遍历，也不会调用拷贝构造函数和析构函数
//}