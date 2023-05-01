class MyCompare{
public://在类中重载()运算符，称为仿函数
    bool operator()(int v1,int v2)const{
        return v1 > v2;
    }
};
void test01(){
    set<int,MyCompare> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);
    for(set<int,MyCompare>::iterator it = s1.begin();it != s1.end(); ++ it){
        cout << *it << " ";
    }
    cout<<endl;
}//set利用仿函数指定排序规则
int main(){
    test01();
    system("pause");
    return 0;
}