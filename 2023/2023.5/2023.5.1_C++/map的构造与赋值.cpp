void printMap(map<int,int>& m){
    for(map<int,int>::iterator it = m.begin();it!=m.end();++it){
        cout << "key = " << it->first << "  value = " << it->second << endl;
    }
    cout << endl;
}
void test01(){
    map<int,int> m1;
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(3, 30));//map插入数据时会自动根据key值进行排序
    m1.insert(pair<int, int>(4, 40));
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(2, 50));//map容器不允许插入重复的key值，所以第二次插入失败
    printMap(m1);
    map<int,int> m2(m1);//map容器的拷贝构造
    printMap(m2);
    map<int,int> m3;
    m3 = m2;//map容器的赋值
    printMap(m3);
}//map容器的构造和赋值
int main(){
    test01();
    system("pause");
    return 0;
}