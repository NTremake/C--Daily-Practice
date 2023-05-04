class myAdd{
public:
    int operator()(int v1, int v2){
        return v1 + v2;
    }//函数对象也可以有参数和返回值
};
class myPrint{
public:
    myPrint(){
        this->count = 0;
    }
    void operator()(string test){
        cout << test << endl;
        ++count;
    }//函数对象可以有自己的状态
    int count;
};
void doPrint(myPrint& mp, string test){
    mp(test);//函数对象可以作为参数传递
}
void test01(){
    myAdd Add;
    cout << Add(10, 10) << endl;
    myPrint Print;
    Print("hello world");
    Print("hello world");
    cout << "myPrint的打印次数：" << Print.count << endl;
    doPrint(Print, "hello world");
}
int main(){
    test01();
    system("pause");
    return 0;
}