#define _CRT_SECURE_NO_WARINGS
#include <iostream>
using namespace std;
#include "boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptId = did;
}

void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ�𣺹���˾���е�����" << endl;
}

string Boss::getDeptName()
{
	return string("�ϰ�");
}