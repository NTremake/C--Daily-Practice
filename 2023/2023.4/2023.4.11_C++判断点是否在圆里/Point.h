#pragma once
#include <iostream>
using namespace std;

class Point
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
class Circle
{
public:
	void setR(int r);
	int getR();
	void setCenter(Point center);
	Point getCenter();
private:
	int R;
	Point Center;
};