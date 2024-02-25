#include "LogIn.h"

//��¼����
void LogIn(string FileName, int type)
{
	Identity* person = nullptr;

	ifstream ifs;
	ifs.open(FileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	int userId = 0;
	string userName;
	string userPassword;
	if (type == 1)
	{
		cout << "����������ѧ�ţ�" << endl;
		cin >> userId;
	}
	else if (type == 2)
	{
		cout << "����������ְ���ţ�" << endl;
		cin >> userId;
	}
	else if (type == 3)
	{
		cout << "���������Ĺ���Ա���˺ţ�" << endl;
		cin >> userId;
	}

	cout << "�����������û�����" << endl;
	cin >> userName;
	cout << "�������������룺" << endl;
	cin >> userPassword;

	//ѧ����¼��֤
	if (type == 1)
	{
		int FileId;
		string fileName2;
		string FilePassword;
		while (ifs >> FileId && ifs >> fileName2 && ifs >> FilePassword)
		{
			if (FileId == userId && fileName2 == userName && FilePassword == userPassword)
			{
				cout << "ѧ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");

				//����ѧ������
				person = new Students(userId, userName, userPassword);
				//��ѧ���Ӳ˵�
				studentMenu(person);

				return;
			}
		}
	}

	//��ʦ��¼��֤
	else if (type == 2)
	{
		int FileId;
		string fileName2;
		string FilePassword;
		while (ifs >> FileId && ifs >> fileName2 && ifs >> FilePassword)
		{
			if (FileId == userId && fileName2 == userName && FilePassword == userPassword)
			{
				cout << "��ʦ��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");

				//������ʦ����
				person = new Teachers(userId, userName, userPassword);
				//�򿪽�ʦ�Ӳ˵�
				teacherMenu(person);

				return;
			}
		}
	}

	//����Ա��¼��֤
	else if (type == 3)
	{
		int fileId;
		string fileName2;
		string FilePassword;
		while (ifs >> fileId && ifs >> fileName2 && ifs >> FilePassword)
		{
			if (fileId == userId && fileName2 == userName && FilePassword == userPassword)
			{
				cout << "����Ա��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				
				//��������Ա����
				person = new Manager(userId, userName, userPassword);
				//�򿪹���Ա�Ӳ˵�
				managerMenu(person);

				return;
			}
		}
	}
	ifs.close();
	cout << "��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}

//����Ա�Ӳ˵�����
void managerMenu(Identity*& manager)
{
	Manager* admini = (Manager*)manager;//������ָ��ǿ��ת���ɣ�����Աָ�룬���ù���Ա�ĳ�Ա����
	int select = 0;
	while (true)
	{
		manager->OpenSubmenu();//���Ӳ˵�
		cin >> select;

		//����˺�
		if (select == 1)
		{
			cout << "����˺�" << endl;
			admini->AddAccount();
		}
		//�鿴�˺�
		else if (select == 2)
		{
			cout << "�鿴�˺���Ϣ" << endl;
			admini->ShowAccounts();
		}
		//�鿴����
		else if (select == 3)
		{
			cout << "�鿴������Ϣ" << endl;
			admini->ShowComputerRooms();
		}
		//���ԤԼ
		else if (select == 4)
		{
			//cout << "���ԤԼ��Ϣ" << endl;
			admini->ClearReservations();
		}
		//ע����¼
		else if (select == 0)
		{
			delete manager;
			manager = nullptr;
			cout << endl << "�˳���¼�ɹ�" << endl << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//ѧ���Ӳ˵�����
void studentMenu(Identity*& student)
{
	int select = 0;
	Students* thisStudent = (Students*)student;
	while (true)
	{
		thisStudent->OpenSubmenu();//���Ӳ˵�
		cin >> select;

		switch (select)
		{
		case 1:
			cout << "����ԤԼ" << endl;
			thisStudent->ApplyReservation();
			break;
		case 2:
			cout << "�鿴����ԤԼ" << endl;
			thisStudent->CheckSelfReservation();
			break;
		case 3:
			cout << "�鿴����ԤԼ" << endl;
			thisStudent->ShowAllReservations();
			break;
		case 4:
			cout << "ȡ��ԤԼ" << endl;
			thisStudent->CancelReservation();
			break;
		case 0:
		{
			delete student;
			student = nullptr;
			cout << endl << "�˳���¼�ɹ�" << endl << endl;
			system("pause");
			system("cls");
			return;
		}
		default:
			cout << "����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//��ʦ�Ӳ˵�����
void teacherMenu(Identity*& teacher)
{
	Teachers* thisTeacher = (Teachers*)teacher;

	int select = 0;
	while (true)
	{
		thisTeacher->OpenSubmenu();//���Ӳ˵�

		cin >> select;
		switch (select)
		{
		case 1:
			cout << "�鿴����ԤԼ" << endl;
			thisTeacher->ShowAllReservations();
			break;
		case 2:
			cout << "���ԤԼ" << endl;
			thisTeacher->CheckReservations();
			break;
		case 0:
		{
			delete teacher;
			teacher = nullptr;
			cout << endl << "�˳���¼�ɹ�" << endl << endl;
			system("pause");
			system("cls");
			return;
		}
		default:
			cout << "����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
