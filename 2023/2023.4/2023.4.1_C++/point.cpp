class Point//头文件里类的引入，只用声明属性和函数，不用写函数的实现
{
public:
	void setX(int x);
	int getX();
	void setY(int y);
	int getY();
private:
	int X;
	int Y;
};
-----------------------------------------
void Point::setX(int x)//类的分文件的引入，不用写权限，需要写类名
{
	X = x;
}
int Point::getX()
{
	return X;
}
void Point::setY(int y)
{
	Y = y;
}
int Point::getY()
{
	return Y;
}