#include <iostream>
using namespace std;

namespace Number_Func
{
    int add(int a, int b)
    {
        return a + b;
    }
    namespace Next_Number//命名空间嵌套
    {
        int add(int a, int b)
        {
            return a + b + 1;
        }
    }
}//自定义命名空间
using namespace Number_Func;
int main() {
    int a = 1, b = 2;
    cout << add(a, b) << endl;
    cout << Number_Func::Next_Number::add(a, b) << endl;
    system("pause");
    return 0;
}