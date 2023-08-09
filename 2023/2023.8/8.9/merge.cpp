#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        if (n == 0) {
            return;
        }
        int i = 0, j = 0;
        for (j = 0; j < m; ++j) {
            for (i = 0; i < n + m; ++i) {
                if (nums2[j] >= nums1[i] && nums2[j] <= nums1[i + 1]) {
                    nums1.insert(nums1.begin() + i + 1, nums2[j]);
                    ++i;
                    break;
                }
                else if (nums2[j] < nums1[i]) {
                    nums1.insert(nums1.begin() + i, nums2[j]);
                    ++i;
                    break;
                }
            }
        }
    }
};
void test01() {
    Solution s;
    vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
    vector<int> nums2 = { 2, 5, 6 };
    s.merge(nums1, 3, nums2, 3);
    nums1.resize(6);
    for (int i = 0; i < nums1.size(); ++i) {
        cout << nums1[i] << "  ";
    }
    cout << endl;
}//
int main() {
    test01();
    system("pause");
    return 0;
}