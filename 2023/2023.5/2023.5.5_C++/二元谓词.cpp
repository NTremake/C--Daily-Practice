class myCompare{
public://二元谓词；二元（两个参数）；谓词（返回bool类型的函数对象）
    bool operator()(int v1, int v2){
        return v1 > v2;
        //return v1 < v2;
    }
};
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
    v1.push_back(50);
    v1.push_back(20);
v1.push_back(30);
sort(v1.begin(), v1.end());//默认从小到大排序
    myPrint(v1);
    cout << "--------------------" << endl;
    sort(v1.begin(), v1.end(), myCompare());
    myPrint(v1);
}//二元谓词，改变排序规则
int main(){
    test01();
    system("pause");
    return 0;
}