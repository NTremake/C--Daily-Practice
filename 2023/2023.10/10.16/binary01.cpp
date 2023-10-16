#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

struct MyPrint : public binary_function<int, int, void>{
    void operator()(int num, int val) const {
        cout << num + val << " " << endl;
    }
};//����������bind1st���󶨵�һ��������bind2nd���󶨵ڶ�������
main() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i + 1);
    }
    for_each(v.begin(), v.end(), bind2nd(MyPrint(), 100));//��100��Ϊ�ڶ�������
    system("pause");
    return 0;
}