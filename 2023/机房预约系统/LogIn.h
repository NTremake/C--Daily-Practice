#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include "globalFile.h"
#include "Students.h"
#include "Teachers.h"
#include "Manager.h"

//登录功能
void LogIn(string FileName, int type);

//进入管理员子菜单界面
void managerMenu(Identity*& manager);

//学生子菜单界面
void studentMenu(Identity*& student);

//老师子菜单界面
void teacherMenu(Identity*& teacher);