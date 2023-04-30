void printPair(pair<string,int>& p){
    cout << "姓名：" << p.first << "  年龄：" << p.second << endl;
}
void test01(){
    pair<string,int> p1("张三",18);
    printPair(p1);
    pair<string,int> p2 = make_pair("李四",20);
    printPair(p2);
}//pair对组的构造与赋值make_pair
int main(){
    test01();
    system("pause");
    return 0;
}