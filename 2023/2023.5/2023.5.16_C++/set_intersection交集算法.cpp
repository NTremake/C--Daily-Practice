void myPrint(int val){
    cout << val << "  ";
}
void test01(){
    vector<int> v1; 
    vector<int> v2;
    for(int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i + 5);
    }
    vector<int> vTarget;
    //最特殊的情况，大容器包含小容器，此时交集为小容器
    vTarget.resize(v1.size() < v2.size() ? v1.size() : v2.size());
    //返回值是一个迭代器，指向交集中最后一个元素的下一个位置,可能有多余的空间，迭代器之后的空间为0
    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, myPrint);
    cout << endl;
    //for_each(vTarget.begin(), vTarget.end(), myPrint);//会把多余的0也打印出来
}//set_intersection交集算法
int main(){
    srand((unsigned int)time(NULL));
    test01();
    system("pause");
    return 0;
}