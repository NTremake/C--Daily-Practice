#pragma once
#include "Identity.h"

class Teachers :public Identity
{
public:
	Teachers();

	Teachers(int Id, string name, string password);

	//�˵�����
	virtual void OpenSubmenu();

	//�鿴����ԤԼ
	void ShowAllReservations();

	//���ԤԼ
	void CheckReservations();

};
