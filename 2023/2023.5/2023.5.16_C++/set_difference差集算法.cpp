class myPrint{
public:
    void operator()(int val){
        cout << val << "  ";
    }
};
void test01(){
    vector<int> v1; 
    vector<int> v2;
    for(int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i + 5);
    }
    vector<int> vTarget;
    vTarget.resize(v1.size() > v2.size() ? v1.size() : v2.size());
    cout << "v1对比v2的差集为：" << endl;
    vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, myPrint());
    cout << endl;
    itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
    cout << "v2对比v1的差集为：" << endl;
    for_each(vTarget.begin(), itEnd, myPrint());
    cout << endl;
}//set_difference差集算法
int main(){
    srand((unsigned int)time(NULL));
    test01();
    system("pause");
    return 0;
}