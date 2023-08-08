#include <iostream>
#include <map>
#include <unordered_map>
#include <iomanip>
using namespace std;

// unordered_map本质上是一个哈希表，而map是一个二叉树
int main() {
    unordered_map<int, string> m(11);
    // size_t number = m.bucket_count();
    // for(int i = 0; i < 200000; ++i) {
    //     char buffer[50];
    //     sprintf(buffer, "元素%d", i);
    //     m.emplace(i, buffer);
    //     if(number != m.bucket_count()) {
    //         number = m.bucket_count();
    //         cout << "bucket_count = " << number << endl;
    //     }
    // }
//----------------------------------------------------------
    // m.max_load_factor(2);//设置负载因子,超过负载因子就会重新分配内存.默认为1.0
    // m.insert({{1, "一号"}, {2, "二号"}, {3, "三号"}});
    // cout << "当前数量：" << m.bucket_count() << endl;
    // cout << "当前负载因子：" << m.load_factor() << endl;
    // m.insert({{4, "四号"}, {5, "五号"}, {6, "六号"}});
    // cout << "当前数量：" << m.bucket_count() << endl;
    // cout << "当前负载因子：" << m.load_factor() << endl;
    // m.insert({{7, "七号"}, {8, "八号"}, {9, "九号"}, {10, "十号"}, {11, "十一号"}});
    // cout << "当前数量：" << m.bucket_count() << endl;
    // cout << "当前负载因子：" << m.load_factor() << endl;
//----------------------------------------------------------
    // m.max_load_factor(5);
    // m.insert({{1, "一号"}, {2, "二号"}, {3, "三号"}, {4, "四号"}, {5, "五号"}});
    // m.insert({{6, "六号"}, {7, "七号"}, {8, "八号"}, {9, "九号"}, {10, "十号"}});
    // m.insert({{11, "十一号"}, {12, "十二号"}, {13, "十三号"}, {14, "十四号"}, {15, "十五号"}});
    // for(auto it = m.begin(); it != m.end(); ++it) { //遍历整个容器
    //     cout << it->first << "  " << it->second << endl;
    // }
    // for(int i = 0; i < m.bucket_count(); ++i) { //遍历容器中的每个桶
    //     cout << "桶" << i << "：";
    //     for(auto it = m.begin(i); it != m.end(i); ++it) {
    //         cout << it->first << "," << it->second << "  ";
    //     }
    //     cout << endl;
    // }
//----------------------------------------------------------
    m.insert({{1, "一号"}, {2, "二号"}, {3, "三号"}});
    m.insert({{4, "四号"}, {5, "五号"}, {6, "六号"}});
    for(int i = 0; i < m.bucket_count(); ++i) {
        cout << "桶" << i << "：";
        for(auto it = m.begin(i); it != m.end(i); ++it) {
            cout << it->first << "," << left << setw(4) << it->second << "  ";
        }
        cout << endl;
    }
    m.insert({{7, "七号"}, {8, "八号"}, {9, "九号"}});
    m.insert({{10, "十号"}, {11, "十一号"}, {12, "十二号"}});
    for(int i = 0; i < m.bucket_count(); ++i) {
        cout << "桶" << i << "：";
        for(auto it = m.begin(i); it != m.end(i); ++it) {
            cout << it->first << "," << left << setw(4) << it->second << "  ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}