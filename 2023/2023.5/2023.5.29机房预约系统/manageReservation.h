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

	//����ԤԼ��¼
	void updateReservation();

	//��¼ԤԼ����
	int _ReservationsNum;

	//��¼ԤԼ��Ϣ,intԤԼ������string�����ڡ���string��1��
	map<int, map<string, string>> _ReservationsData;

	//��ȡԤԼ��Ϣ�������������һ��ԤԼ��Ϣ
	map<string, string> substrReservation(string fileReservation, map<string, string>& smallmap);

	//��ʾһ��ԤԼ��Ϣ
	void showReservation(map<string, string>& smallmap);
};