#include "Teachers.h"

Teachers::Teachers()
{
}

Teachers::Teachers(int Id, string name, string password)
{
	this->_UserId = Id;
	this->_UserName = name;
	this->_UserPassword = password;

	this->InitComputerRoom();
}

//�˵�����
void Teachers::OpenSubmenu()
{
	cout << "��ӭ��ʦ��" << this->_UserName << "��¼" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.�鿴����ԤԼ        |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.�˳���¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ�����";
}

//�鿴����ԤԼ
void Teachers::ShowAllReservations()
{
	manageReservation manageRes;
	if (manageRes._ReservationsNum == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << endl;
	for (int i = 1; i <= manageRes._ReservationsNum; ++i)
	{
		cout << i << ". ";
		manageRes.showReservation(manageRes._ReservationsData[i]);

	}
	cout << endl;
	system("pause");
	system("cls");
}

//���ԤԼ
void Teachers::CheckReservations()
{
	manageReservation manageRes;
	if (manageRes._ReservationsNum == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << endl << "����˵�ԤԼ��¼���£�" << endl << endl;

	int count = 0;
	vector<int> vcheckKey;
	for (int i = 1; i <= manageRes._ReservationsNum; ++i) 
	{
		if (manageRes._ReservationsData[i]["ԤԼ״̬"] == "1") 
		{
			vcheckKey.push_back(i);
			cout << ++count << ". ";
			manageRes.showReservation(manageRes._ReservationsData[i]);
		}
	}

	cout << endl << "����0�˳���ˣ�" << endl;
	cout << "��������Ҫ��˵�ԤԼ��ţ�" << endl;
	int select;
	int ret;
	while (true)
	{
		cin >> select;
		if(select > 0 && select <= count)
		{
			cout << endl << "��������˽��>>   1.ͨ��   2.��ͨ��   0.�˳����" << endl;
			cin >> ret;
			if (ret == 1)
			{
				manageRes._ReservationsData[vcheckKey[select - 1]]["ԤԼ״̬"] = "2";
				manageRes.updateReservation();
				cout << "���ͨ����" << endl;
				system("pause");
				system("cls");
				return;
			}
			else if (ret == 2)
			{
				manageRes._ReservationsData[vcheckKey[select - 1]]["ԤԼ״̬"] = "-1";
				manageRes.updateReservation();
				++this->_ComputerRoom[stoi(manageRes._ReservationsData[vcheckKey[select - 1]]["����"]) - 1];
				this->SaveComputerRoom();
				cout << "��˲�ͨ����" << endl;
				system("pause");
				system("cls");
				return;
			}
			else if (ret == 0)
			{
				cout << "���˳���ˣ�" << endl;
				system("pause");
				system("cls");
				return;
			}
			else
			{
				cout << "����������������룡" << endl;
			}
		}
		else if (select == 0)
		{
			cout << "���˳���ˣ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "����������������룡" << endl;
		}
	}
	system("pause");
	system("cls");
}
