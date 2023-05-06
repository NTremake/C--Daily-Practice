void myPrint(vector<bool> &v){
    for(vector<bool>::iterator it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}
void test01(){
    vector<bool> v1;
    v1.push_back(true);
    v1.push_back(false);
    v1.push_back(true);
    v1.push_back(false);
    myPrint(v1);
    vector<bool> v2;
    v2.resize(v1.size());//需要预先重新指定大小，开辟空间
transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());//逻辑非,取反
//logical_and逻辑与；logical_or逻辑或
    myPrint(v2);
}//内建函数，逻辑取反
int main(){
    test01();
    system("pause");
    return 0;
}