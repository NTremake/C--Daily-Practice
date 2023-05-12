class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int fast = 1, slow = 1;
        while (fast < n) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];//将不重复的元素放到前面
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};
//leetcode只截取前slow个元素，后面的元素不管
void test01(){
    vector<int> nums = {0, 0, 1, 1, 2, 3, 4, 4};
    Solution s;
    int ret = s.removeDuplicates(nums);
    cout << ret << endl;
    for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it){
        cout << *it << "  ";
    }
    cout << endl;
}//高效双指针查重
int main(){
    test01();
    system("pause");
    return 0;
}