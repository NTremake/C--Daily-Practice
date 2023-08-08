#include <iostream>
#include <map>
#include <unordered_map>
#include <iomanip>
using namespace std;

// unordered_map��������һ����ϣ����map��һ��������
int main() {
    unordered_map<int, string> m(11);
    // size_t number = m.bucket_count();
    // for(int i = 0; i < 200000; ++i) {
    //     char buffer[50];
    //     sprintf(buffer, "Ԫ��%d", i);
    //     m.emplace(i, buffer);
    //     if(number != m.bucket_count()) {
    //         number = m.bucket_count();
    //         cout << "bucket_count = " << number << endl;
    //     }
    // }
//----------------------------------------------------------
    // m.max_load_factor(2);//���ø�������,�����������Ӿͻ����·����ڴ�.Ĭ��Ϊ1.0
    // m.insert({{1, "һ��"}, {2, "����"}, {3, "����"}});
    // cout << "��ǰ������" << m.bucket_count() << endl;
    // cout << "��ǰ�������ӣ�" << m.load_factor() << endl;
    // m.insert({{4, "�ĺ�"}, {5, "���"}, {6, "����"}});
    // cout << "��ǰ������" << m.bucket_count() << endl;
    // cout << "��ǰ�������ӣ�" << m.load_factor() << endl;
    // m.insert({{7, "�ߺ�"}, {8, "�˺�"}, {9, "�ź�"}, {10, "ʮ��"}, {11, "ʮһ��"}});
    // cout << "��ǰ������" << m.bucket_count() << endl;
    // cout << "��ǰ�������ӣ�" << m.load_factor() << endl;
//----------------------------------------------------------
    // m.max_load_factor(5);
    // m.insert({{1, "һ��"}, {2, "����"}, {3, "����"}, {4, "�ĺ�"}, {5, "���"}});
    // m.insert({{6, "����"}, {7, "�ߺ�"}, {8, "�˺�"}, {9, "�ź�"}, {10, "ʮ��"}});
    // m.insert({{11, "ʮһ��"}, {12, "ʮ����"}, {13, "ʮ����"}, {14, "ʮ�ĺ�"}, {15, "ʮ���"}});
    // for(auto it = m.begin(); it != m.end(); ++it) { //������������
    //     cout << it->first << "  " << it->second << endl;
    // }
    // for(int i = 0; i < m.bucket_count(); ++i) { //���������е�ÿ��Ͱ
    //     cout << "Ͱ" << i << "��";
    //     for(auto it = m.begin(i); it != m.end(i); ++it) {
    //         cout << it->first << "," << it->second << "  ";
    //     }
    //     cout << endl;
    // }
//----------------------------------------------------------
    m.insert({{1, "һ��"}, {2, "����"}, {3, "����"}});
    m.insert({{4, "�ĺ�"}, {5, "���"}, {6, "����"}});
    for(int i = 0; i < m.bucket_count(); ++i) {
        cout << "Ͱ" << i << "��";
        for(auto it = m.begin(i); it != m.end(i); ++it) {
            cout << it->first << "," << left << setw(4) << it->second << "  ";
        }
        cout << endl;
    }
    m.insert({{7, "�ߺ�"}, {8, "�˺�"}, {9, "�ź�"}});
    m.insert({{10, "ʮ��"}, {11, "ʮһ��"}, {12, "ʮ����"}});
    for(int i = 0; i < m.bucket_count(); ++i) {
        cout << "Ͱ" << i << "��";
        for(auto it = m.begin(i); it != m.end(i); ++it) {
            cout << it->first << "," << left << setw(4) << it->second << "  ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}