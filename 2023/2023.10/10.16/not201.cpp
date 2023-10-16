#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

struct MyCompare : public binary_function<int, int, bool> {
    bool operator()(int num, int val) const {
        return num > val;
    }
};
struct IsEven5 : public unary_function<int, bool> {
    bool operator()(int num) const {
        return num < 5;
    }
};
void test01() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    sort(v1.begin(), v1.end(), not2(MyCompare()));//二元谓词取反
    for(int& num : v1) {
        cout << num << endl;
    }
    cout << "-----------------" << endl;
    vector<int> v2;
    copy_if(v1.begin(), v1.end(), back_inserter(v2), not1(IsEven5()));//一元谓词取反
    for(int& num : v2) {
        cout << num << endl;
    }
}//取反适配器，not1是一元谓词的取反；not2是二元谓词的取反
int main() {
    test01();
    system("pause");
    return 0;
}