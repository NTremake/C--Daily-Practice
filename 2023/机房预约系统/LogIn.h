#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include "globalFile.h"
#include "Students.h"
#include "Teachers.h"
#include "Manager.h"

//��¼����
void LogIn(string FileName, int type);

//�������Ա�Ӳ˵�����
void managerMenu(Identity*& manager);

//ѧ���Ӳ˵�����
void studentMenu(Identity*& student);

//��ʦ�Ӳ˵�����
void teacherMenu(Identity*& teacher);