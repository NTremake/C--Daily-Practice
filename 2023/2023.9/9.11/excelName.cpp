#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string str;
        while(columnNumber != 0)
        {
            if(columnNumber % 26 != 0)
            {
                str += columnNumber % 26 + '@';
                columnNumber -= columnNumber % 26;
            }
            else
            {
                str += 'Z';
                columnNumber -= 26;
            }
            columnNumber = columnNumber / 26;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};// 把数字转换成Excel表格名字
int main() {
    Solution s;
    cout << s.convertToTitle(52) << endl;
    system("pause");
    return 0;
}