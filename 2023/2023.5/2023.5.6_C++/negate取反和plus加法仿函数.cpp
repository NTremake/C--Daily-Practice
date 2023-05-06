void test01(){//仿函数本质上是一个类，重载了()运算符
    negate<int> n;//一元仿函数，正负取反函数
    cout << n(50) << endl;
    cout << negate<int>()(50) << endl;//匿名对象
    plus<int> p;//二元仿函数，加法函数
    cout << p(10, 20) << endl;
    cout << plus<int>()(10, 20) << endl;
}//取反和加法仿函数对象
int main(){
    test01();
    system("pause");
    return 0;
}