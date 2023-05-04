class myCompare{
public:
    bool operator()(int v1, int v2){
        return v1 > v2;
    }
};
void printMap(map<int, int, myCompare>& m){
    for(map<int, int, myCompare>::iterator it = m.begin(); it != m.end(); ++it){
        cout << "key=" << it->first << "  value=" << it->second << endl;
    }
    cout << endl;
}
void test01(){
    map<int, int, myCompare> m1;
    m1.insert(make_pair(1,10));
    m1.insert(make_pair(5,50));
    m1.insert(make_pair(4,50));
    m1.insert(make_pair(2,20));
    m1.insert(make_pair(3,30));
    printMap(m1);
}//map容器的自定义排序
int main(){
    test01();
    system("pause");
    return 0;
}