#include <iostream>
using namespace std;

class Father {
public:
    virtual void print() = 0;
};
class Son1 : public Father {
public:
    void print() {
        cout << "Son1��print������" << endl;
    }
    void show() {
        cout << "Son1��dynamic_cast���Ժ���" << endl;
    }
};
class Son2 : public Father {
public:
    void print() {
        cout << "Son2��print������" << endl;
    }
    void show() {
        cout << "Son2��ǿת���Ժ���" << endl;
    }
};//dynamic_castֻ�����ڶ�̬���ͣ������麯������
int main() {
    cout << "������һ�����֣�" << endl;
    int num;
    cin >> num;
    Father *p1 = nullptr;
    switch(num) {
        case 1: {
            p1 = new Son1;
            p1->print();
            Son1 *p2 = dynamic_cast<Son1 *>(p1);
            p2->show();//dynamic_cast���÷�
            delete p2;
            break;
        }
        case 2: {
            p1 = new Son2();
            p1->print();
            Son2 *p2 = (Son2 *)p1;//c����ǿת
            p2->show();
            delete p2;
            break;
        }
    }
    delete p1;
    system("pause");
    return 0;
}