#include <iostream>
using namespace std;
#include "speechManager.h"
#include <ctime>

int main() {
	srand((unsigned int )time(nullptr));
	speechManager sm;
	int choice = 0;
	while (true) {
		sm.show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice) {

		case 1:		//��ʼ����
			sm.startSpeech();
			break;
		case 2:		//�鿴������¼
			sm.loadRecord();
			sm.showRecord();
			break;
		case 3:		//��ձ���
			sm.clearRecord();
			break;
		case 0:		//�˳�����
			sm.exitSystem();
			break;
		default:
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}