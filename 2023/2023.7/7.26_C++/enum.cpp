#include <iostream>
using namespace std;

//enum colors {red, green, blue};//Ĭ��ֵΪ0,1,2��������
enum colors {red = 2, green = 3, blue = 1};//ö�ٳ���
int main() {
    // colors c = colors(2);//����ֱ�Ӹ�ֵΪ2
    colors c = red;//ö�ٱ�����ֻ�ܸ�ֵΪö�ٳ���
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