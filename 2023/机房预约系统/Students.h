#pragma once
#include "Identity.h"

//学生类
class Students :public Identity
{
public:
	Students();

	Students(int Id, string name, string password);

	//菜单界面
	virtual void OpenSubmenu();

	//申请预约
	void ApplyReservation();

	//查看自身预约
	void CheckSelfReservation();

	//查看所有预约
	void ShowAllReservations();

	//取消预约
	void CancelReservation();

	//机房为空时，禁止预约,返回true表示空
	bool IsEmpty();
};
