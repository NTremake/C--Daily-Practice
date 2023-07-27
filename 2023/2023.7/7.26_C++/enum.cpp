#include <iostream>
using namespace std;

//enum colors {red, green, blue};//默认值为0,1,2这样排序
enum colors {red = 2, green = 3, blue = 1};//枚举常量
int main() {
    // colors c = colors(2);//不能直接赋值为2
    colors c = red;//枚举变量，只能赋值为枚举常量
    cout << c << endl;
    switch(c) {
        case red:
            cout << "red" << endl;
            break;
        case green:
            cout << "green" << endl;
            break;
        case blue:
            cout << "blue" << endl;
            break;
        default:
            cout << "default" << endl;
            break;
    }
    system("pause");
    return 0;
}