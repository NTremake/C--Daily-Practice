class myCompare{
public://函数对象的返回值是bool，称作谓词
    bool operator()(int val){//只有一个参数的称为一元谓词
        //return *it > 8;//__find_if的参数是迭代器
        return val > 8;
    }
};
void test01(){
    vector<int> v1;
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    //查找容器中是否有5,返回值是一个迭代器,myCompare()是一个匿名函数对象
    vector<int>::iterator it = find_if(v1.begin(), v1.end(), myCompare());
    if(it == v1.end()){
        cout << "未找到" << endl;
    }
    else{
        cout<<"找到了目标元素：" << *it << endl;
    }
}
int main(){
    test01();
    system("pause");
    return 0;
}