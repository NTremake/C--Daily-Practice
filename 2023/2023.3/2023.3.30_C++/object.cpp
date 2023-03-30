const float PI = 3.14;
class Circle//创建类Circle，圆
{
public://访问权限
	int R;//类的属性(成员属性、变量)
	float ZC()//类的行为,可以定义多个函数。(成员行为、函数)
	{
		return 2 * PI * R;
	}
float MJ()
{
return PI*R*R;
}
};
int main()
{
	Circle c1;//根据类创建对象c1
	c1.R = 10;//给圆对象c1的属性R进行赋值
	cout << "圆的周长=" << c1.ZC() << endl;
cout << "圆的面积=" << c1.MJ() << endl;
	return 0;
}