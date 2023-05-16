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
    vTarget.resize(v1.size() + v2.size());
    vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, myPrint());
    cout << endl;
    //for_each(vTarget.begin(), vTarget.end(), myPrint());//会把多余的0也打印出来
}//set_union并集算法
int main(){
    srand((unsigned int)time(NULL));
    test01();
    system("pause");
    return 0;
}