//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Person {
//public:
//    Person() {
//        cout << "Ĭ�Ϲ��캯��" << endl;
//    }
//    Person(string name) : name(name) {
//        cout << "�вι��캯����" << this->name << endl;
//    }
//    Person(const Person& p) : name(p.name) {
//        cout << "�������캯����" << this->name << endl;
//    }
//    Person operator=(const Person& p) {
//        cout << "��ֵ��������أ�" << this->name << endl;
//        return *this;
//    }
//    ~Person() {
//        cout << "����������" << this->name << endl;
//    }
//    string name;
//};
//int main() {
//    vector<Person> v;
//    v.emplace_back("����");
//    cout << "1Capacity = " << v.capacity() << endl;
//    v.emplace_back("����");
//    cout << "2Capacity = " << v.capacity() << endl;
//    v.emplace_back("����");
//    cout << "3Capacity = " << v.capacity() << endl;
//    cout << "------------------" << endl;
//    /*for (auto a : v) {
//        cout << a.name << "  " << endl;
//    }*/
//    for (const auto& a : v) {
//        cout << a.name << "  " << endl;
//    }//���������ã��Ͳ�����ÿ������캯������������
//    cout << "------------------" << endl;
//    for (vector<Person>::iterator it = v.begin(); it != v.end(); ++it) {
//		cout << (*it).name << "  " << endl;
//	}//��ʵֱ��ʹ�õ�����������Ҳ������ÿ������캯������������
//}