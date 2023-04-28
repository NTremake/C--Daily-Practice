void test01(){
    set<int>s1;
    s1.insert(30);
    s1.insert(20);
    s1.insert(10);
    s1.insert(40);
    s1.insert(40);
    set<int>::iterator pos = s1.find(40);//find返回的是迭代器
    if(pos!=s1.end()){
        cout << "找到了元素：" << *pos << endl;
    }
    else{
        cout << "未找到元素" << endl;
    }
    int num = s1.count(40);//set的元素不允许重复，所以count的返回值只能是0或1
    cout << "40的个数为：" << num << endl;
}//set的查找与统计
int main(){
    test01();
    system("pause");
    return 0;
}