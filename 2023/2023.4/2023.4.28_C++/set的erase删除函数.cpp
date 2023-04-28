void printSet(set<int>&s){
    for(set<int>::iterator it = s.begin();it!=s.end();++it){
        cout << *it << " ";
    }
    cout << endl;
}
void test01(){
    set<int>s1;
    s1.insert(30);
    s1.insert(20);
    s1.insert(10);
    s1.insert(40);
    s1.erase(s1.begin());//删除的是10，因为set容器是有序的
    printSet(s1);
    s1.erase(30);//删除的是30
    printSet(s1);
    s1.erase(s1.begin(),s1.end());//清空
    printSet(s1);
    //s1.clear();//清空
}//set的
int main(){
    test01();
    system("pause");
    return 0;
}