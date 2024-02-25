#include "manageReservation.h"

//��ԤԼ��Ϣ����map�У��������
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
		this->substrReservation(date, smallReservation);//��ȡ����
		this->substrReservation(time, smallReservation);//��ȡʱ���
		this->substrReservation(roomID, smallReservation);//��ȡ������
		this->substrReservation(studentID, smallReservation);//��ȡѧ��id
		this->substrReservation(studentName, smallReservation);//��ȡѧ������
		this->substrReservation(status, smallReservation);//��ȡԤԼ״̬

		++this->_ReservationsNum;
		this->_ReservationsData.insert(make_pair(this->_ReservationsNum, smallReservation));
		smallReservation.clear();
	}
	ifs.close();
}

//����ԤԼ��¼
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

//��ȡԤԼ��Ϣ�������������һ��ԤԼ��Ϣ
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

//��ʾһ��ԤԼ��Ϣ
void manageReservation::showReservation(map<string, string>& smallmap)
{
	if (smallmap["����"] == "1")
	{
		cout << "����:" << "��һ" << "   ";
	}
	else if (smallmap["����"] == "2")
	{
		cout << "����:" << "�ܶ�" << "   ";
	}
	else if (smallmap["����"] == "3")
	{
		cout << "����:" << "����" << "   ";
	}
	else if (smallmap["����"] == "4")
	{
		cout << "����:" << "����" << "   ";
	}
	else if (smallmap["����"] == "5")
	{
		cout << "����:" << "����" << "   ";
	}
	else
	{
		cout << "����:" << "����" << "   ";
	}
	cout << "ʱ���:" << (smallmap["ʱ���"] == "1" ? "����" : "����") << "   ";
	cout << "����:" << smallmap["����"] << "   ";
	cout << "ѧ��:" << smallmap["ѧ��"] << "   ";
	cout << "ѧ������:" << smallmap["ѧ������"] << "   ";
	if (smallmap["ԤԼ״̬"] == "1")
	{
		cout << "ԤԼ״̬:�����" << endl;
	}
	else if (smallmap["ԤԼ״̬"] == "2")
	{
		cout << "ԤԼ״̬:ԤԼ�ɹ�" << endl;
	}
	else if (smallmap["ԤԼ״̬"] == "-1")
	{
		cout << "ԤԼ״̬:ԤԼδͨ����ԤԼʧ��" << endl;
	}
	else
	{
		cout << "ԤԼ״̬:ԤԼ��ȡ��" << endl;
	}
}