#pragma once
#include "Identity.h"

//ѧ����
class Students :public Identity
{
public:
	Students();

	Students(int Id, string name, string password);

	//�˵�����
	virtual void OpenSubmenu();

	//����ԤԼ
	void ApplyReservation();

	//�鿴����ԤԼ
	void CheckSelfReservation();

	//�鿴����ԤԼ
	void ShowAllReservations();

	//ȡ��ԤԼ
	void CancelReservation();

	//����Ϊ��ʱ����ֹԤԼ,����true��ʾ��
	bool IsEmpty();
};
