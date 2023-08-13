#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T1, typename T2>
T1 findif(const T1& begin, const T1& end, T2 func) {
    for(auto it = begin; it != end; ++it) {
        if(func(*it)) {
            return it;
        }
    }
    return end;
}// find_if��ʵ��ԭ��
template <typename T>
class Show {
public:
    T m_num;
    Show(const T& num) :m_num(num) {}
    bool operator()(T& a) {
        if(a != m_num) {
            return false;
        }
        return true;
    }
};// �ѷº���Ҳд��ģ��
int main() {
    vector<int> vec = { 1,2,3,4,5 };
    auto it = findif(vec.begin(), vec.end(), Show<int>(3));
    if(it != vec.end()) {
        cout << *it << endl;
    }
    else {
        cout << "û���ҵ�" << endl;
    }
    system("pause");
    return 0;
}