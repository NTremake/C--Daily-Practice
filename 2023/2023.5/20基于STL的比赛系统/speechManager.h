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
	//���캯��
	speechManager();

	//����������Ա
	void createSpeaker();

	//�˵�����
	void show_Menu();

	//��ʼ����
	void startSpeech();

	//��ǩ
	void speechDraw();

	//�������
	void speechContest();

	//�鿴�����÷�
	void showScore();

	//�����¼
	void saveRecord();

	//��ȡ�ļ�
	void loadRecord();

	//��ʾ�����¼
	void showRecord();

	//��ռ�¼
	void clearRecord();

	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	//��������¼������
	vector<vector<string>> m_vRecord;

	//�˳�����
	void exitSystem();

	//��������
	~speechManager();

	//��ʼ������
	void initSpeech();

	//��Ա����
	//��һ�ֱ���ѡ������ 12��
	vector<int> v1;

	//�ڶ��ֱ���ѡ������ 6��
	vector<int> v2;

	//ʤ��ǰ�������� 3��
	vector<int> vVictory;

	//��ű���Լ���Ӧ����ѡ�� ����
	map<int, Speaker> m_Speaker;

	//��������
	int m_Index;
};
