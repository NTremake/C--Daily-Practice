void myPrint(vector<int> &v){
    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}
void test01(){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(40);
    v1.push_back(20);
    v1.push_back(50);
    v1.push_back(30);
    myPrint(v1);
    sort(v1.begin(), v1.end(), greater<int>());//大于；底层默认是lessss<int>()
    myPrint(v1);
}//内建函数，大于
int main(){
    test01();
    system("pause");
    return 0;
}