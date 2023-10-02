#include <iostream>
using namespace std;

int main() {
    char ch1;
    cin.get(ch1);
    cout << ch1 << endl;
    //cin.ignore();//ºöÂÔµô»º³åÇøµÄÒ»¸ö×Ö·û
    //cin.ignore(2);//ºöÂÔ2¸ö×Ö·û
    cin.ignore(3, '\n');//ºöÂÔ3¸ö×Ö·û£¬Óöµ½\nÖ±½Ó½áÊø
    cin.get(ch1);
    cout << ch1 << endl;
    system("pause");
    return 0;
}