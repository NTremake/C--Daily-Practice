#include <iostream>
using namespace std;

int main() {
    //try��������Ҫ����Ĵ����
    try {
        int a = 0;
        cout << "ѡ���쳣���룺" << "1.const cahr*  2.int  3.string" << endl;
        cin >> a;
        if(a == 1) {
            throw "const char*���͵��쳣";//throw�׳���ͬ���͵��쳣
        }
        if(a == 2) {
            throw "int���͵��쳣";
        }
        if(a == 3) {
            throw string("string���͵��쳣");
        }
    }//try�׳��쳣֮�󣬱���catch���ס
    catch (const char* i) {
        cout << "�쳣�����ǣ�" << i << endl;
    }
    catch (int i) {
        cout << "�쳣�����ǣ�" << i << endl;
    }
    catch (string ss) {
        cout << "�쳣�����ǣ�" << ss << endl;
    }
    system("pause");
    return 0;
}