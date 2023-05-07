void print01(int val){
    cout << val << " ";
}
class print02{
public:
    void operator()(int val){
        cout << val << " ";
    }
};
void test01(){
    vector<int> v1;
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    for_each(v1.begin(), v1.end(), print01);//普通函数
    cout << endl;
    for_each(v1.begin(), v1.end(), print02());//仿函数
    cout << endl;
}//for_each()算法，遍历容器
int main(){
    test01();
    system("pause");
    return 0;
}