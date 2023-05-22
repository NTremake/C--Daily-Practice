#pragma once
#include <iostream>
using namespace std;
#include "speaker.h"
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <iomanip>
#include <fstream>
#define FILENAME "speech.csv"

class speechManager {
public:
	//构造函数
	speechManager();

	//创建参赛人员
	void createSpeaker();

	//菜单功能
	void show_Menu();

	//开始比赛
	void startSpeech();

	//抽签
	void speechDraw();

	//比赛打分
	void speechContest();

	//查看晋级得分
	void showScore();

	//保存记录
	void saveRecord();

	//读取文件
	void loadRecord();

	//显示往届记录
	void showRecord();

	//清空记录
	void clearRecord();

	//判断文件是否为空
	bool fileIsEmpty;

	//存放往届记录的容器
	vector<vector<string>> m_vRecord;

	//退出功能
	void exitSystem();

	//析构函数
	~speechManager();

	//初始化容器
	void initSpeech();

	//成员属性
	//第一轮比赛选手容器 12人
	vector<int> v1;

	//第二轮比赛选手容器 6人
	vector<int> v2;

	//胜出前三名容器 3人
	vector<int> vVictory;

	//存放编号以及对应具体选手 容器
	map<int, Speaker> m_Speaker;

	//比赛轮数
	int m_Index;
};
