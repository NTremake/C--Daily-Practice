void myprint(vector<int>& v){
    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}
void test01(){
    vector<int> v1;
    for(int i = 0; i < 10; ++i){
        v1.push_back(i);
    }
    bool ret = binary_search(v1.begin(), v1.end(), 7);
    if(ret){
        cout << "找到了" << endl;
    }
    else{
        cout << "没找到" << endl;
    }
}//binary_search()在有序序列中查找元素，返回bool值(必须是升序)
int main(){
    test01();
    system("pause");
    return 0;
}