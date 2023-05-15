void test01(){															
    vector<int> v; 
    for(int i = 1; i < 101; ++i) {
        v.push_back(i);
    }
    //第三个参数是起始值
    int total = accumulate(v.begin(), v.end(), 0);
    cout << "total = " << total << endl;
}//累加算法
int main(){
    srand((unsigned int)time(NULL));
    test01();
    system("pause");
    return 0;
}