#include <iostream>
using namespace std;

int main() {
    //try里面是需要处理的代码块
    try {
        int a = 0;
        cout << "选择异常代码：" << "1.const cahr*  2.int  3.string" << endl;
        cin >> a;
        if(a == 1) {
            throw "const char*类型的异常";//throw抛出不同类型的异常
        }
        if(a == 2) {
            throw "int类型的异常";
        }
        if(a == 3) {
            throw string("string类型的异常");
        }
    }//try抛出异常之后，必须catch借接住
    catch (const char* i) {
        cout << "异常类型是：" << i << endl;
    }
    catch (int i) {
        cout << "异常类型是：" << i << endl;
    }
    catch (string ss) {
        cout << "异常类型是：" << ss << endl;
    }
    system("pause");
    return 0;
}