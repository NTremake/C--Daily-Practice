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

	//菜单界面
	virtual void OpenSubmenu();

	//添加账号
	void AddAccount();

	//查看账号
	void ShowAccounts();

	//查看机房信息
	void ShowComputerRooms();

	//清空预约记录
	void ClearReservations();

	//账号id查重,返回true表示重复
	bool CheckUserId(int id, string filename);

	//机房信息初始化
	void InitComputerRoom();

};
