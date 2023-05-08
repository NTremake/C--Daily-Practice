void myprint(vector<int>& v){
    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}
void test01(){
    vector<int> v1;
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(0);
    v1.push_back(3);
    v1.push_back(3);
    vector<int>::iterator it = adjacent_find(v1.begin(), v1.end());
    if(it == v1.end()){
        cout << "没有找到相邻重复元素" << endl;
    }
    else{
        cout << "找到相邻重复元素：" << *it << endl;
    }
}//adjacent_find()查找相邻重复元素，返回相邻元素的第一个位置的迭代器
int main(){
    test01();
    system("pause");
    return 0;
}