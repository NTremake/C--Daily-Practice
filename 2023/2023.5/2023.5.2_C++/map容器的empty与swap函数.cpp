void printMap(map<int, int>& m){
    for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it){
        cout << "key=" << it->first << "  value=" << it->second << endl;
    }
    cout << endl;
}
void test01(){
    map<int,int> m1;
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(3, 30));
    m1.insert(pair<int, int>(3, 30));//map容器不允许插入重复的key值，但是可以插入重复的value值,所有size仍然为3
    if(m1.empty()){
        cout << "m1为空" << endl;
    }
    else{
        cout << "m1不为空" << endl;
        cout << "m1的大小为：" << m1.size() << endl;
    }
    map<int, int> m2;
    m2.insert(pair<int, int>(4, 40));
    m2.insert(pair<int, int>(5, 50));
    m2.insert(pair<int, int>(6, 60));
    cout << "交换前：" << endl;
    printMap(m1);
    printMap(m2);
    m1.swap(m2);
    cout << "交换后：" << endl;
    printMap(m1);
    printMap(m2);
}//map容器的size和swap函数
int main(){
    test01();
    system("pause");
    return 0;
}