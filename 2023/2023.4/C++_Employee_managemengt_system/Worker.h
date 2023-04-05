#pragma once
#include <iostream>
using namespace std;
#include <string>

class Worker//员工父类，纯虚
{
public:
	virtual void showInfo() = 0;//显示职工信息
	virtual string getDeptName() = 0;//获取岗位名称
	int m_id;
	string m_name;
	int m_deptId;
};