#define _CRT_SECURE_NO_WARINGS
#include "employee.h"

Employee::Employee(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptId = did;
}

void Employee::showInfo()//��ʾְ����Ϣ
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ����ɾ���ί�еĹ�����" << endl;
}

string Employee::getDeptName()//��ȡ��λ����
{
	return string("����Ա��");
}
