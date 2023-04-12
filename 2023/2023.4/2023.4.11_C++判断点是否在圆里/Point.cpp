#define _CRT_SECURE_NO_WARINGS
#include <iostream>
using namespace std;
#include "Point.h"

void Point::setX(int x)
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
//---------------------------------
void Circle::setR(int r)
{
	R = r;
}
int Circle::getR()
{
	return R;
}
void Circle::setCenter(Point center)
{
	Center = center;
}
Point Circle::getCenter()
{
	return Center;
}