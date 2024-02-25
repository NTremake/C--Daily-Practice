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

	//������Ϣ��ʼ��
	void InitComputerRoom()
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

	//���������Ϣ
	void SaveComputerRoom()
	{
		ofstream ofs;
		ofs.open(COMPUTERROOM_FILE, ios::trunc);
		for (unsigned int i = 0; i < this->_ComputerRoom.size(); ++i)
		{
			ofs << i + 1 << "   " << this->_ComputerRoom[i] << endl;
		}
		ofs.close();
	}
protected:
	int _UserId = 0;
	string _UserName;
	string _UserPassword;
	vector<int> _ComputerRoom;//������Ϣ
};