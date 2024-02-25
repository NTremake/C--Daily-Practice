#pragma once
#include <iostream>
using namespace std;
#include "globalFile.h"
#include <fstream>
#include <map>
#include <string>
#include <vector>

class manageReservation
{
public:
	manageReservation();

	//更新预约记录
	void updateReservation();

	//记录预约条数
	int _ReservationsNum;

	//记录预约信息,int预约条数，string“日期”，string“1”
	map<int, map<string, string>> _ReservationsData;

	//截取预约信息，六个参数组成一条预约信息
	map<string, string> substrReservation(string fileReservation, map<string, string>& smallmap);

	//显示一条预约信息
	void showReservation(map<string, string>& smallmap);
};