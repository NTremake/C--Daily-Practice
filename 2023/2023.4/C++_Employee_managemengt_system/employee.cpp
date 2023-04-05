#define _CRT_SECURE_NO_WARINGS
#include "employee.h"

Employee::Employee(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptId = did;
}

void Employee::showInfo()//显示职工信息
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成经理委托的工作。" << endl;
}

string Employee::getDeptName()//获取岗位名称
{
	return string("基层员工");
}
