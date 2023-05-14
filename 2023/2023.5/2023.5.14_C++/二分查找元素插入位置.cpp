class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        int mid = 0;
        while (left < right) {//二分查找
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};//查找元素插入位置
void test01(){
    vector<int> nums = {0, 1, 2, 3, 4, 5};
    Solution s;
    cout << s.searchInsert(nums, 6) << endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}