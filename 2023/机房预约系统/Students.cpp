#include "Students.h"

Students::Students()
{

}

Students::Students(int Id, string name, string password)
{
	this->_UserId=Id;
	this->_UserName=name;
	this->_UserPassword=password;

	this->InitComputerRoom();
}

//��ѧ���˵�
void Students::OpenSubmenu()
{
	cout << "��ӭͬѧ��" << this->_UserName << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ        |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����ԤԼ        |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.ȡ��ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.�˳���¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ�����";
}

//����ԤԼ
void Students::ApplyReservation()
{
	manageReservation manageRes;
	if (this->IsEmpty())
	{
		cout << "����Ϊ�գ���ʱ����ԤԼ��" << endl;
		return;
	}
	cout << "��������ʱ��Ϊ��һ��������" << endl;
	cout << "������ԤԼʱ�䣺" << endl;
	cout << "1����һ" << "   ";
	cout << "2���ܶ�" << "   ";
	cout << "3������" << "   ";
	cout << "4������" << "   ";
	cout << "5������" << "   ";
	cout << "6������" << endl;
	int date = 0;
	int time = 0;
	int room = 0;
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 6)
		{
			break;
		}
		cout << "�����������������룡" << endl;
	}
	cout << "������ԤԼʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	while (true)
	{
		cin >> time;
		if (time == 1 || time == 2)
		{
			break;
		}
		cout << "�����������������룡" << endl;
	}
	//�ж�ԤԼʱ���Ƿ��ظ�
	for (map<int, map<string, string>>::iterator it = manageRes._ReservationsData.begin(); it != manageRes._ReservationsData.end(); ++it)
	{
		if (it->second["����"] == to_string(date) && it->second["ʱ���"] == to_string(time) && it->second["ѧ��"] == to_string(this->_UserId) && (it->second["ԤԼ״̬"] == to_string(1) || it->second["ԤԼ״̬"] == to_string(2)))
		{
			cout << "���Ѿ�ԤԼ����ʱ��εĻ�����������ѡ��" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	cout << "��ѡ�������" << endl;
	for (unsigned int i = 0; i < this->_ComputerRoom.size(); ++i)
	{
		cout << i + 1 << "�Ż�������Ϊ��" << this->_ComputerRoom[i] << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			--this->_ComputerRoom[room - 1];
			break;
		}
		cout << "�����������������룡" << endl;
	}
	this->SaveComputerRoom();
	cout << "ԤԼ�ɹ����Ѿ��ύ��ˣ�" << endl;

	ofstream ofs;
	ofs.open(RESERVATIONS_FILE, ios::app);
	ofs << "����:" << date << "   ";
	ofs << "ʱ���:" << time << "   ";
	ofs << "����:" << room << "   ";
	ofs << "ѧ��:" << this->_UserId << "   ";
	ofs << "ѧ������:" << this->_UserName << "   ";
	ofs << "ԤԼ״̬:" << 1 << endl;
	ofs.close();

	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Students::CheckSelfReservation()
{
	manageReservation managereservation;
	if (managereservation._ReservationsNum == 0)
	{
		cout << endl << "��ԤԼ��¼��" << endl << endl;
		system("pause");
		system("cls");
		return;
	}
	int count = 0;
	cout << endl;
	for (int i = 1; i <= managereservation._ReservationsNum; ++i)
	{
		if (stoi(managereservation._ReservationsData[i]["ѧ��"]) == this->_UserId)
		{
			managereservation.showReservation(managereservation._ReservationsData[i]);
			++count;
		}
	}
	cout << endl;
	if (count == 0)
	{
		cout << endl << "��ԤԼ��¼��" << endl << endl;
	}
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Students::ShowAllReservations()
{
	manageReservation managereservation;
	if (managereservation._ReservationsNum == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	
	cout << endl;
	for (int i = 1; i <= managereservation._ReservationsNum; ++i)
	{
		cout << i << ". ";
		managereservation.showReservation(managereservation._ReservationsData[i]);
	}
	cout << endl;
	system("pause");
	system("cls");
}

//ȡ��ԤԼ
void Students::CancelReservation()
{
	manageReservation managereservation;
	if (managereservation._ReservationsNum == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << endl << "����0��������һ����" << endl;
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ������������Ҫȡ���ļ�¼��" << endl;
	int count = 0;
	vector<int> vkey;

	//������������ԤԼ��¼��key�洢��vkey��
	for (int i = 1; i <= managereservation._ReservationsNum; ++i)
	{
		if (stoi(managereservation._ReservationsData[i]["ѧ��"]) == this->_UserId && (stoi(managereservation._ReservationsData[i]["ԤԼ״̬"]) == 1 || stoi(managereservation._ReservationsData[i]["ԤԼ״̬"]) == 2))
		{
			vkey.push_back(i);
			cout <<++count << ". ";
			managereservation.showReservation(managereservation._ReservationsData[i]);
		}
	}
	if (count == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	//�ı�ԤԼ״̬���������ļ�
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= count)
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				managereservation._ReservationsData[vkey[select - 1]]["ԤԼ״̬"] = "0";
				managereservation.updateReservation();
				++this->_ComputerRoom[stoi(managereservation._ReservationsData[vkey[select - 1]]["����"]) - 1];
				this->SaveComputerRoom();
				cout << "ȡ���ɹ���" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
		cout << "�����������������룡" << endl;
	}
	system("pause");
	system("cls");
}

//����Ϊ��ʱ����ֹԤԼ,trueΪ��
bool Students::IsEmpty()
{
	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);
	int ret;
	int computer;
	while (ifs >> ret && ifs >> computer)
	{
		if (computer != 0)
		{
			return false;
		}
	}
	ifs.close();
	return true;
}
