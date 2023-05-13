class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int j = 0;j < nums.size();++j) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                ++i;
            }
        }
        return i;
    }
};//移除指定元素，快慢指针法
void test01(){
    vector<int> nums = {0, 0, 1, 1, 2, 3, 4, 4};
    Solution s;
    int len = s.removeElement(nums, 1);
    for (int i = 0; i < len; ++i) {
        cout << nums[i] << "  ";
    }
}
int main(){
    test01();
    system("pause");
    return 0;
}