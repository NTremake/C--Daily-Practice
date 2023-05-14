class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        for(int i = s.size() - 1; i >= 0; --i){
            if(s[i] == ' ' && s[i + 1] != ' ' && s[i + 1] != '\0'){
                return len;
            }
            else if(s[i] != ' '){
                ++len;
            }
        }
        return len;
    }
};//计算最后一个单词的长度
void test01(){
    string s1 = "Hello World   aa  ";
    Solution s;
    cout << s.lengthOfLastWord(s1) << endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}