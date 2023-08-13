#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

class Person {
public:
    string m_name;
    int m_age;
    Person(const string& name, const int& age) :m_name(name), m_age(age) {}
    bool Personless(const Person& p) {
        if(m_age < p.m_age) {
            return true;
        }
        return false;
    }
};
class myGrater {
public:
    bool operator()(Person& p1, Person& p2) {
        if(p1.m_age > p2.m_age) {
            return true;
        }
        return false;
    }
};
class myLess {
public:
    bool operator()(Person& p1, Person& p2) {
        if(p1.m_age < p2.m_age) {
            return true;
        }
        return false;
    }
};
int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    vector<Person> vec;
    for(int i = 0; i < 6; ++i) {
        string name = "张三";
        vec.push_back(Person(name + to_string(i), 20 + i));
    }
    random_shuffle(vec.begin(), vec.end());
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        cout << "姓名：" << it->m_name << ",年龄：" << it->m_age << endl;
    }
    sort(vec.begin(), vec.end(), myLess());
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        cout << "姓名：" << it->m_name << ",年龄：" << it->m_age << endl;
    }
    system("pause");
    return 0;
}