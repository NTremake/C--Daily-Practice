#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
class Show {
public:
    void operator()(T& a) {
        cout << a << "  ";
    }
};// 把仿函数也写成模板
template <typename T>
void Show1(T& a) {
    cout << a << "  ";
}// 普通函数模板
template <typename T1, typename T2>
void foreach(T1 begin, T1 end, T2 func) {
    for(auto it = begin; it != end; ++it) {
        func(*it);
    }
}// for_each的实现原理
int main() {
    vector<int> vec = { 1,2,3,4,5 };
    foreach(vec.begin(), vec.end(), Show<int>());
    cout << endl;
    foreach(vec.begin(), vec.end(), Show1<int>);
    cout << endl;
    vector<string> vec2 = { "aaa","bbb","ccc","ddd","eee" };
    foreach(vec2.begin(), vec2.end(), Show<string>());
    cout << endl;
    foreach(vec2.begin(), vec2.end(), Show1<string>);
    cout << endl;
    system("pause");
    return 0;
}