#pragma once
#include "Identity.h"
#include "globalFile.h"
#include "Students.h"
#include "Teachers.h"

class Manager :public Identity
{
public:
	Manager();

	Manager(int id, string name, string password);

	//�˵�����
	virtual void OpenSubmenu();

	//����˺�
	void AddAccount();

	//�鿴�˺�
	void ShowAccounts();

	//�鿴������Ϣ
	void ShowComputerRooms();

	//���ԤԼ��¼
	void ClearReservations();

	//�˺�id����,����true��ʾ�ظ�
	bool CheckUserId(int id, string filename);

	//������Ϣ��ʼ��
	void InitComputerRoom();

};
