#pragma once
#include <iostream>
using namespace std;
#include <string>

class Worker//Ա�����࣬����
{
public:
	virtual void showInfo() = 0;//��ʾְ����Ϣ
	virtual string getDeptName() = 0;//��ȡ��λ����
	int m_id;
	string m_name;
	int m_deptId;
};