void printMap(map<int, int>& m){
    for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it){
        cout << "key=" << it->first << "  value=" << it->second << endl;
    }
    cout << endl;
}
void test01(){
    map<int,int> m1;
    m1.insert(pair<int,int>(1,10));//map的四种插入方式
    m1.insert(make_pair(2, 20));
    m1.insert(map<int,int>::value_type(3,30));
    m1[4] = 40;//不推荐使用这种方法
    printMap(m1);
    cout<<m1[4]<<endl;
    //cout<<m1[5]<<endl;//如果key不存在,会创建一个新的键值对,值为0
    m1.erase(m1.begin());
    m1.erase(3);//删除key为3的键值对
    printMap(m1);
    m1.erase(m1.begin(),m1.end());//清空
    //m1.clear();
    printMap(m1);
}//map容器插入和删除
int main(){
    test01();
    system("pause");
    return 0;
}