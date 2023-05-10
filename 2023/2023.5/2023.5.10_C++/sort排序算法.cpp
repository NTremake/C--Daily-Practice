class myPrint{
public:
    void operator()(int val){
        cout << val << "  ";
    }
};
void test01(){
    vector<int> v;
    for(int i = 0; i < 10; ++i){
        int a = rand() % 6;
        v.push_back(a);
    }
    sort(v.begin(), v.end());//默认升序
    for_each(v.begin(), v.end(), myPrint());
    cout << endl;
    sort(v.begin(), v.end(), greater<int>());//降序
    for_each(v.begin(), v.end(), myPrint());
    cout << endl;
}
int main(){
    srand((unsigned int)time(NULL));//需要ctime头文件
    test01();
    system("pause");
    return 0;
}