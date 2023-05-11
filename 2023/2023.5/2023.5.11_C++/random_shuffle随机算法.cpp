void myPrint(int val){
    cout << val << "  ";
}
void test01(){
    vector<int> v;
    for(int i = 0; i < 10; ++i){
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}//random_shuffle()随机打乱函数的使用
int main(){
    srand((unsigned int)time(NULL));//使每次随机都都不一样
    test01();
    system("pause");
    return 0;
}