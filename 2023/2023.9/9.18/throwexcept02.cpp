#include <iostream>
using namespace std;

int main() {
    //string s = "123";//���쳣
    string s = "";//��Ч����
    //string s = "123981640291728320847238162308";//����int��Χ
    cin >> s;
    try {
        int a = stoi(s);
    }
    catch (invalid_argument&) {
        cout << "invalid_argument&�쳣" << endl;
    }
    catch (out_of_range&) {
        cout << "out_of_range&�쳣" << endl;
    }
    catch (...) {
        cout << "something else error" << endl;
    }
    system("pause");
    return 0;
}