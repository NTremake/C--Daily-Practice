#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int pair : nums) {
            map[pair]++;
        }
        for(int pair : nums) {
            if(map[pair] == 1) {
                return pair;
            }
        }
        return 0;
    }
};
class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int e: nums) ret ^= e;
        return ret;
    }
};// 找出只出现一次的数字
int main() {
    Solution s;
    vector<int> v{1, 2, 3, 4, 4, 5, 5, 3, 1};
    cout << s.singleNumber(v) << endl;
    system("pause");
    return 0;
}