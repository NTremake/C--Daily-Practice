class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0 || len == 1) {
            return len;
        }
        vector<int>::iterator it = nums.begin();
        while (it != nums.end()){
            it = adjacent_find(nums.begin(), nums.end());
            if(it != nums.end()){
                nums.erase(it);
                --len;
            }
        }
        return len;
    }
};
void test01(){
    vector<int> nums = {0, 1, 1, 1, 1, 2, 3, 4};
    Solution s;
    int ret = s.removeDuplicates(nums);
    cout << ret << endl;
    for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it){
        cout << *it << "  ";
    }
    cout << endl;
}//adjacent_find()对相邻重复元素的删除，效率低
int main(){
    test01();
    system("pause");
    return 0;
}