class myPrint{
public:
    void operator()(int val){
        cout << val << "  ";
    }
};
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.empty()){
                return digits;
        }
        for(int i = digits.size() - 1; i >= 0; --i){
            if(digits[i] != 9){
                digits[i] += 1;
                return digits;
            }
            else {
                digits[i] = 0;
            }
        }
        if(digits[0] == 0) {
            digits.insert(digits.begin(), 1);
            return digits;
        }
        return digits;
    }
};//时间加一进一位
void test01(){
    vector<int> v1 = {1, 9, 9, 9, 9};
    Solution s;
    for_each(v1.begin(), v1.end(), myPrint());
    cout << endl;
    s.plusOne(v1);
    for_each(v1.begin(), v1.end(), myPrint());
    cout << endl;
}
int main(){
    srand((unsigned int)time(nullptr));
    test01();
    system("pause");
    return 0;
}