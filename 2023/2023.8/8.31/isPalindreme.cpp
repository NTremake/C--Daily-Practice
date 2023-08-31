#include <iostream>
#include <string>
using namespace std;

class Solution1 {
public:
    bool isPalindrome(string s) {
        string sGood;
        for(char& ch : s) {
            if(isalnum(ch)) {
                sGood += tolower(ch);
            }
        }
        string sGoodRev(sGood.rbegin(), sGood.rend());
        return sGood == sGoodRev;
    }
};
class Solution {
public:
    bool isPalindrome(string s) {
        string sGood;
        for(char& ch : s) {
            if(isalnum(ch)) {
                sGood += tolower(ch);
            }
        }
        int left = 0;
        int right = sGood.size() - 1;
        while(left < right) {
            if(sGood[left] != sGood[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};// �ж��ַ�������ĸ���ǲ��ǻ���
int main() {
    Solution s1;
    cout << s1.isPalindrome("AB man,,, a plan, a canal: PanamBa") << endl;
    system("pause");
    return 0;
}