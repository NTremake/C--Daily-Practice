#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#include "globalFile.h"
#include "manageReservation.h"

//用户身份的抽象类
class Identity
{
public:
	//不同用户打开子菜单
	virtual void OpenSubmenu() = 0;

	//设置用户ID
	void SetUserId(int id)
	{
		this->_UserId = id;
	}
	//获取用户ID
	int GetUserId()
	{
		return this->_UserId;
	}
	//设置用户名
	void SetUserName(string name)
	{
		this->_UserName = name;
	}
	//获取用户名
	string GetUserPassword()
	{
		return this->_UserPassword;
	}
	//设置用户密码
	void SetUserPassword(string password)
	{
		this->_UserPassword = password;
	}
	//获取用户密码
	string GetUserName()
	{
		return this->_UserName;
	}

	void SetComputerRoom(vector<int>& room)
	{
		this->_ComputerRoom = room;
	}
	vector<int> GetComputerRoom()
	{
		return this->_ComputerRoom;
	}

protected:
	int _UserId;
	string _UserName;
	string _UserPassword;
	vector<int> _ComputerRoom;//机房信息
};