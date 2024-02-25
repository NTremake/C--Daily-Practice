#pragma once
#include "Identity.h"

class Teachers :public Identity
{
public:
	Teachers();

	Teachers(int Id, string name, string password);

	//菜单界面
	virtual void OpenSubmenu();

	//查看所有预约
	void ShowAllReservations();

	//审核预约
	void CheckReservations();

};
