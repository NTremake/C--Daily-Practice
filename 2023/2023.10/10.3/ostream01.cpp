#include <iostream>
using namespace std;

int main() {
    char ch1;
    cin.get(ch1);
    cout << ch1 << endl;
    //cin.ignore();//���Ե���������һ���ַ�
    //cin.ignore(2);//����2���ַ�
    cin.ignore(3, '\n');//����3���ַ�������\nֱ�ӽ���
    cin.get(ch1);
    cout << ch1 << endl;
    system("pause");
    return 0;
}