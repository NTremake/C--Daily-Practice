#pragma once
#include <iostream>
using namespace std;
#include "Worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
#define FILENAME "empFile.txt"

class workerManager
{
public:
	workerManager();

	void showMenu();//�˵�

	void exitSystem();//�˳�����

	void add_Emp();//���ְ��

	void save();//�����ļ�

	bool m_fileIsEmpty;//�ж��ļ��Ƿ�Ϊ��

	int get_empNum();//��ȡ�ļ��е�����

	void init_Emp();//��ʼ��ְ����Ϣ

	void show_Emp();//��ʾԱ����Ϣ

	void del_Emp();//ɾ��ְ��

	int isExist(int id);//�ж�ְ���Ƿ���ڣ������������е�λ��

	void mod_Emp();//�޸�ְ����Ϣ

	void find_Emp();//����ְ��

	void sort_Emp();//ְ������

	void clean_File();//����ļ�

	int m_EmpNum;//ְ������

	Worker** m_EmpArray;//ָ��ְ�����飬�������ְ�������ְ��

	~workerManager();
};