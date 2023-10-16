#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

struct MyPrint : public binary_function<int, int, void>{
    void operator()(int num, int val) const {
        cout << num + val << " " << endl;
    }
};//绑定适配器，bind1st，绑定第一个参数；bind2nd，绑定第二个参数
main() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i + 1);
    }
    for_each(v.begin(), v.end(), bind2nd(MyPrint(), 100));//将100绑定为第二个参数
    system("pause");
    return 0;
}