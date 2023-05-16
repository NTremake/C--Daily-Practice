void myPrint(int val){
    cout << val << "  ";
}
void test01(){
    vector<int> v; 
    v.resize(10);
    fill(v.begin(), v.end(), 100);//将容器内元素填充为100
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}//重新填充容器
int main(){
    srand((unsigned int)time(NULL));
    test01();
    system("pause");
    return 0;
}