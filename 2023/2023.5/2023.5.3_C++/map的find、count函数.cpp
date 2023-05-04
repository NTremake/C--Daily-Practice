void test01(){
    map<int,int> m1;
    m1.insert(pair<int,int>(1,10));
    m1.insert(make_pair(2,20));
    m1.insert(make_pair(3,30));
    map<int,int>::iterator it = m1.find(3);//返回的是迭代器
    //m1.find(3)->second = 100;
    cout<<"key="<<it->first<<"  value="<<it->second<<endl;
    int num = m1.count(3);
    cout<<"key值为3的数是否存在"<<num<<endl;//1存在，0不存在
}//map容器
int main(){
    test01();
    system("pause");
    return 0;
}