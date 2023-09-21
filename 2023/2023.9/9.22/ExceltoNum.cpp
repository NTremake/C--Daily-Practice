#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int num = 0;
        int index = 0;
        while(columnTitle.size() > 0) {
            num += (columnTitle.back() % 64) * pow(26, index);
            index++;
            columnTitle.pop_back();
        }
        return num;
    }
};//��Excel�������ת��������
int main() {
    cout << Solution().titleToNumber("AB") << endl;
    cout << (int)'A' << endl;
    system("pause");
    return 0;
}