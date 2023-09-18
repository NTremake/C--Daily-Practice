#include <iostream>
using namespace std;

int main() {
    //string s = "123";//无异常
    string s = "";//无效参数
    //string s = "123981640291728320847238162308";//超出int范围
    cin >> s;
    try {
        int a = stoi(s);
    }
    catch (invalid_argument&) {
        cout << "invalid_argument&异常" << endl;
    }
    catch (out_of_range&) {
        cout << "out_of_range&异常" << endl;
    }
    catch (...) {
        cout << "something else error" << endl;
    }
    system("pause");
    return 0;
}