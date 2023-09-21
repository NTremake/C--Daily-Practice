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
};//将Excel表格名字转换成数字
int main() {
    cout << Solution().titleToNumber("AB") << endl;
    cout << (int)'A' << endl;
    system("pause");
    return 0;
}