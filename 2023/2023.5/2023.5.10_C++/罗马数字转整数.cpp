class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        for(int i = 0; i < s.size(); ++i){
            int val = Values[s[i]];//map的下标运算符[]，如果key不存在，会自动创建一个key，值为0
            if(i < s.size() - 1 && val < Values[s[i+1]]){//如果当前值小于下一个值，说明是特殊情况，需要减去当前值
                ret -= val;
            }else{
                ret += val;
            }
        }
        return ret;
    }
private:
    map<char, int> Values = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
};
void test01(){
    cout << Solution().romanToInt("MCMXCIV") << endl;
}//罗马数字转整数
int main()
{
    test01();
    system("pause");
    return 0;
}