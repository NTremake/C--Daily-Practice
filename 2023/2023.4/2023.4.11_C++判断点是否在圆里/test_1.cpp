#define _CRT_SECURE_NO_WARINGS
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include <ctime>
#include <Windows.h>
#include "Point.h"

//class Point
//{
//public:
//	void setX(int x)
//	{
//		X = x;
//	}
//	int getX()
//	{
//		return X;
//	}
//	void setY(int y)
//	{
//		Y = y;
//	}
//	int getY()
//	{
//		return Y;
//	}
//private:
//	int X;
//	int Y;
//};
//class Circle
//{
//public:
//	void setR(int r)
//	{
//		R = r;
//	}
//	int getR()
//	{
//		return R;
//	}
//	void setCenter(Point center)
//	{
//		Center = center;
//	}
//	Point getCenter()
//	{
//		return Center;
//	}
//private:
//	int R;
//	Point Center;
//};
void isInCircle(Circle& c, Point& p)
{
	int distance =
		((c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()))
		+ ((c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY()));
	int rDistance = c.getR() * c.getR();
	if (distance == rDistance)
	{
		cout << "点在圆上" << endl;
	}
	else if (distance < rDistance)
	{
		cout << "点在圆内" << endl;
	}
	else
	{
		cout << "点在圆外" << endl;
	}
}
int main()
{
	Point p1;
	Point center;
	Circle c;
	p1.setX(0);
	p1.setY(10);
	center.setX(0);
	center.setY(0);
	c.setCenter(center);
	c.setR(10);
	isInCircle(c, p1);
	return 0;
}