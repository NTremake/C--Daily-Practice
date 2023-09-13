#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> num;
        for(int& i:nums) {
            num[i]++;
            if(num[i] > nums.size() / 2) {
                return i;
            }
        }
        return 0;
    }
};//�ҳ������г��ִ����������֣�����n/2)
int main() {
    vector<int> v{1, 2, 3, 5, 5, 5, 5, 5};
    Solution s;
    cout << s.majorityElement(v) << endl;
    system("pause");
    return 0;
}