class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()){
            return "";
        }
        int length = strs[0].size();
        int count = strs.size();
        for(int i = 0; i < length; ++i){
            char c = strs[0][i];//第j个字符串，第i个字符
            for(int j = 1; j < count; ++j){
                if(i == strs[j].size() || strs[j][i] != c){
                    return strs[0].substr(0, i);//substr(起始位置，长度)截取字符串；
                }
            }
        }
        return strs[0];
    }
    vector<string> v1;
};
void test01(){
    Solution s1;
    vector<string> v1;
    v1.push_back("flower");
    v1.push_back("flow");
    v1.push_back("flight");
    cout << s1.longestCommonPrefix(v1) << endl;
}//最长公共前缀
int main()
{
    test01();
    system("pause");
    return 0;
}