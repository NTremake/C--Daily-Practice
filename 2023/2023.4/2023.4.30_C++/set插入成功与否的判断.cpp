void printSet(multiset<int>& m){
for(multiset<int>::iterator it=m.begin();it!=m.end();++it){
        cout << *it << " ";
    }
    cout << endl;
}
void test01(){
    set<int>s1;
    pair<set<int>::iterator,bool> ret = s1.insert(10);//pair能接收两个值，一个是迭代器，一个是bool值
    if(ret.second){
        cout << "第一次插入成功" << endl;
    }
    else{
        cout << "第一次插入失败" << endl;
    }
    ret = s1.insert(10);//set容器不允许插入重复的元素，所以第二次插入失败
    if(ret.second){
        cout << "第二次插入成功" << endl;
    }
    else{
        cout << "第二次插入失败" << endl;
    }
    multiset<int> m1;
    m1.insert(10);
    m1.insert(10);
    m1.insert(10);
    printSet(m1);//multiset可以插入重复数据
}//set的插入成功与否
int main(){
    test01();
    system("pause");
    return 0;
}