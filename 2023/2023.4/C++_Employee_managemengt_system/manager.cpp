#define _CRT_SECURE_NO_WARINGS
#include <iostream>
using namespace std;
#include "manager.h"

Manager::Manager(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptId = did;
}

void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ������ϰ�ί�еĹ��������·������Ա����" << endl;
}

string Manager::getDeptName()
{
	return string("����");
}