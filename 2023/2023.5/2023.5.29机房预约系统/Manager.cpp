#include "Manager.h"

Manager::Manager()
{

}

Manager::Manager(int id, string name, string password)
{
	this->_UserId = id;
	this->_UserName = name;
	this->_UserPassword = password;
}

//������Ϣ��ʼ��
void Manager::InitComputerRoom()
{
	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);
	int ret;
	int computerNum;
	while (ifs >> ret && ifs >> computerNum)
	{
		this->_ComputerRoom.push_back(computerNum);
	}
	ifs.close();
}

//�˵�����
void Manager::OpenSubmenu()
{
	//�򿪹���Ա�˵�
	cout << "��ӭ����Ա��" << this->_UserName << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.�˳���¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ�����";
}

//����˺�
void Manager::AddAccount()
{
	string fileName;
	int select = 0;
	while (true)
	{
		cout << "����������˺ŵ����ͣ�" << endl;
		cout << "1�����ѧ��" << endl;
		cout << "2�������ʦ" << endl;

		cin >> select;

		switch (select)
		{
		case 1:
			fileName = STUDENTS_FILE;
			break;
		case 2:
			fileName = TEACHERS_FILE;
			break;
		default:
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}

		if (select == 1 || select == 2)
		{
			break;
		}
	}

	ofstream ofs;
	ofs.open(fileName, ios::out | ios::app);
	while (true)
	{
		int id = 0;
		string name = "";
		string password = "";
		switch (select)
		{
		case 1:
		{
			cout << "������ѧ�ţ�" << endl;
			cin >> id;
			if (this->CheckUserId(id, fileName))
			{
				cout << "���˺��Ѵ��ڣ����������룡" << endl;
				break;
			}
			cout << "������ѧ��������" << endl;
			cin >> name;
			cout << "���������룺" << endl;
			cin >> password;
			ofs << id << "  " << name << "  " << password << "  " << endl;
			cout << "��ӳɹ���" << endl;
			ofs.close();
			system("pause");
			system("cls");
			return;
		}
		case 2:
		{
			cout << "������ְ����ţ�" << endl;
			cin >> id;
			if (this->CheckUserId(id, fileName))
			{
				cout << "���˺��Ѵ��ڣ����������룡" << endl;
				break;
			}
			cout << "��������ʦ������" << endl;
			cin >> name;
			cout << "���������룺" << endl;
			cin >> password;
			ofs << id << "  " << name << "  " << password << "  " << endl;
			cout << "��ӳɹ���" << endl;
			ofs.close();
			system("pause");
			system("cls");
			return;
		}
		}
	}
}

//�鿴�˺�
void Manager::ShowAccounts()
{
	int select = 0;
	int fileUserId;
	string fileUserName;
	string fileUserPassword;
	char ch;
	ifstream ifs;
	while (true)
	{
		cout << "��ѡ��鿴���ݣ�" << endl;
		cout << "1���鿴����ѧ��" << endl;
		cout << "2���鿴������ʦ" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			//�ļ�������
			ifs.open(STUDENTS_FILE, ios::in);
			if (!ifs.is_open())
			{
				cout << "ѧ���ļ������ڣ�" << endl;
				system("pause");
				system("cls");
				return;
			}
			//�ļ�Ϊ��
			ifs >> ch;
			if (ifs.eof())
			{
				cout << "ѧ���ļ�Ϊ�գ�" << endl;
				ifs.close();
				system("pause");
				system("cls");
				return;
			}
			//�ļ������Ҳ�Ϊ��
			ifs.putback(ch);
			while (ifs >> fileUserId && ifs >> fileUserName && ifs >> fileUserPassword)
			{
				cout << "ѧ�ţ�" << fileUserId << "\t\t������" << fileUserName << "\t\t���룺" << fileUserPassword << endl;
			}
			ifs.close();
			system("pause");
			system("cls");
			return;
		case 2:
			ifs.open(TEACHERS_FILE, ios::in);
			if (!ifs.is_open())
			{
				cout << "��ʦ�ļ������ڣ�" << endl;
				system("pause");
				system("cls");
				return;
			}
			ifs >> ch;
			if (ifs.eof())
			{
				cout << "��ʦ�ļ�Ϊ�գ�" << endl;
				ifs.close();
				system("pause");
				system("cls");
				return;
			}
			ifs.putback(ch);
			while (ifs >> fileUserId && ifs >> fileUserName && ifs >> fileUserPassword)
			{
				cout << "ְ����ţ�" << fileUserId << "\t\t������" << fileUserName << "\t\t���룺" << fileUserPassword << endl;
			}
			ifs.close();
			system("pause");
			system("cls");
			return;
		default:
			cout << "�����������������룡" << endl;
			break;
		}
	}
}

//�鿴������Ϣ
void Manager::ShowComputerRooms()
{
	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�����ļ������ڣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�����ļ�Ϊ�գ�" << endl;
		ifs.close();
		system("pause");
		system("cls");
		return;
	}
	ifs.putback(ch);
	int roomId;
	int computerNum;
	while (ifs >> roomId && ifs >> computerNum)
	{
		cout << "������ţ�" << roomId << "\t����������" << computerNum << endl;
	}
	ifs.close();
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::ClearReservations()
{
	ofstream ofs;
	ofs.open(RESERVATIONS_FILE, ios::trunc);
	ofs.close();
	cout << endl << "���ԤԼ�ɹ���" << endl << endl;
	system("pause");
	system("cls");
}

//�˺�id����,����true��ʾ�ظ�
bool Manager::CheckUserId(int id, string filename)
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ���ʧ�ܣ�" << endl;
		return false;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ�գ�" << endl;
		ifs.close();
		return false;
	}

	ifs.putback(ch);
	int fileId;
	string fileUserName;
	string fileUserPassword;
	while (ifs >> fileId && ifs >> fileUserName && ifs >> fileUserPassword)
	{
		if (id == fileId)
		{
			//cout << "���˺��Ѵ��ڣ����������룡" << endl;
			ifs.close();
			return true;
		}
	}
	return false;
}