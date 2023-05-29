#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#include "globalFile.h"
#include "manageReservation.h"

//�û���ݵĳ�����
class Identity
{
public:
	//��ͬ�û����Ӳ˵�
	virtual void OpenSubmenu() = 0;

	//�����û�ID
	void SetUserId(int id)
	{
		this->_UserId = id;
	}
	//��ȡ�û�ID
	int GetUserId()
	{
		return this->_UserId;
	}
	//�����û���
	void SetUserName(string name)
	{
		this->_UserName = name;
	}
	//��ȡ�û���
	string GetUserPassword()
	{
		return this->_UserPassword;
	}
	//�����û�����
	void SetUserPassword(string password)
	{
		this->_UserPassword = password;
	}
	//��ȡ�û�����
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
	vector<int> _ComputerRoom;//������Ϣ
};