#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person() :_Name("����"){};
    Person(string name) :_Name(name){};
    ~Person() {
        cout << "��������" << this->_Name << endl;
    }
    string _Name;
};
int main() {
    int a = 0;
    cout << "�����룺" << endl;
    cin >> a;
    try {
        Person p1("����");//�쳣�������try����Ķ���
        if(a == 1) {
            throw string("�쳣����");
        }

    }
    catch (string& b) {
        cout << b << endl;
    }
    system("pause");
    return 0;
}