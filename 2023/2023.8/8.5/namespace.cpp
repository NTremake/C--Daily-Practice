#include <iostream>
using namespace std;

namespace Number_Func
{
    int add(int a, int b)
    {
        return a + b;
    }
    namespace Next_Number//�����ռ�Ƕ��
    {
        int add(int a, int b)
        {
            return a + b + 1;
        }
    }
}//�Զ��������ռ�
using namespace Number_Func;
int main() {
    int a = 1, b = 2;
    cout << add(a, b) << endl;
    cout << Number_Func::Next_Number::add(a, b) << endl;
    system("pause");
    return 0;
}