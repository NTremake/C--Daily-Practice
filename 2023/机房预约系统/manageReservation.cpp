#include "manageReservation.h"

//把预约信息存入map中，方便管理
manageReservation::manageReservation()
{
	string date;
	string time;
	string roomID;
	string studentID;
	string studentName;
	string status;
	this->_ReservationsNum = 0;

	string filekey;
	string filevalue;
	map<string, string> smallReservation;
	ifstream ifs;
	ifs.open(RESERVATIONS_FILE, ios::in);
	while (ifs >> date && ifs >> time && ifs >> roomID && ifs >> studentID && ifs >> studentName && ifs >> status)
	{
		//cout<<date<<" "<<time<<" "<<studentID<<" "<<studentName<<" "<<roomID<<" "<<status<<endl;
		this->substrReservation(date, smallReservation);//截取日期
		this->substrReservation(time, smallReservation);//截取时间段
		this->substrReservation(roomID, smallReservation);//截取机房号
		this->substrReservation(studentID, smallReservation);//截取学生id
		this->substrReservation(studentName, smallReservation);//截取学生姓名
		this->substrReservation(status, smallReservation);//截取预约状态

		++this->_ReservationsNum;
		this->_ReservationsData.insert(make_pair(this->_ReservationsNum, smallReservation));
		smallReservation.clear();
	}
	ifs.close();
}

//更新预约记录
void manageReservation::updateReservation()
{
	if (this->_ReservationsNum == 0)
	{
		return;
	}
	ofstream ofs;
	ofs.open(RESERVATIONS_FILE, ios::out | ios::trunc);
	for (map<int, map<string, string>>::iterator it = this->_ReservationsData.begin(); it != this->_ReservationsData.end(); ++it)
	{
		for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); ++mit)
		{
			ofs << mit->first << ":" << mit->second << "   ";
		}
		ofs << endl;
	}
	ofs.close();
}

//截取预约信息，六个参数组成一条预约信息
map<string, string> manageReservation::substrReservation(string fileReservation, map<string, string>& smallmap)
{
	int pos = fileReservation.find(":");
	string key;
	string value;
	if (pos != -1)
	{
		key = fileReservation.substr(0, pos);
		value = fileReservation.substr(pos + 1, fileReservation.size() - pos - 1);
		smallmap.insert(make_pair(key, value));
	}
	return smallmap;
}

//显示一条预约信息
void manageReservation::showReservation(map<string, string>& smallmap)
{
	if (smallmap["日期"] == "1")
	{
		cout << "日期:" << "周一" << "   ";
	}
	else if (smallmap["日期"] == "2")
	{
		cout << "日期:" << "周二" << "   ";
	}
	else if (smallmap["日期"] == "3")
	{
		cout << "日期:" << "周三" << "   ";
	}
	else if (smallmap["日期"] == "4")
	{
		cout << "日期:" << "周四" << "   ";
	}
	else if (smallmap["日期"] == "5")
	{
		cout << "日期:" << "周五" << "   ";
	}
	else
	{
		cout << "日期:" << "周六" << "   ";
	}
	cout << "时间段:" << (smallmap["时间段"] == "1" ? "上午" : "下午") << "   ";
	cout << "机房:" << smallmap["机房"] << "   ";
	cout << "学号:" << smallmap["学号"] << "   ";
	cout << "学生姓名:" << smallmap["学生姓名"] << "   ";
	if (smallmap["预约状态"] == "1")
	{
		cout << "预约状态:审核中" << endl;
	}
	else if (smallmap["预约状态"] == "2")
	{
		cout << "预约状态:预约成功" << endl;
	}
	else if (smallmap["预约状态"] == "-1")
	{
		cout << "预约状态:预约未通过，预约失败" << endl;
	}
	else
	{
		cout << "预约状态:预约已取消" << endl;
	}
}