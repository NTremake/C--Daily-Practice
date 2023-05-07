class MyPrint{
public:
    void operator()(int val){
        cout << left << setw(4) << negate<int>()(val);
    }
};
void test01(){
    vector<int> v1;
    for(int i = 0; i < 10; ++i){
        v1.push_back(i);
    }
    for(vector<int>::iterator it = v1.begin(); it != v1.end(); ++it){
        cout << left << setw(4) << *it;
    }
    cout << endl;
    for_each(v1.begin(), v1.end(), MyPrint());//for_each()的遍历条件中可以进行一些运算
    cout << endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}