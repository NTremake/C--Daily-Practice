class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        for(int i = 0;i<s.size();++i){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                s1.push(s[i]);//左括号入栈
            }
            else{
                if(s[i]==')'){
                    if(s1.empty() || s1.top()!='('){
                        return false;//右括号与栈顶元素不匹配
                    }
                }
                if(s[i]=='}'){
                    if(s1.empty() || s1.top()!='{'){
                        return false;
                    }
                }
                if(s[i]==']'){
                    if(s1.empty() || s1.top()!='['){
                        return false;
                    }
                }
                s1.pop();//匹配成功，栈顶元素出栈
            }
        }
        if(!s1.empty()){
            return false;//栈不为空，说明左括号多
        }
        return true;
    }
};
void test01(){
    Solution s;
    string str = "([)]";
    bool ret = s.isValid(str);
    cout << ret << endl;
    string str1 = "{[()]}";
    ret = s.isValid(str1);
    cout << ret << endl;
}//有效的括号配队
int main()
{
    test01();
    system("pause");
    return 0;
}