#include <iostream>
using namespace std;
#include <iomanip>
#include <string>

struct st_girl {
	int No;
	string name;
	struct st_girl *next;
};
void test01() {
	st_girl *head = nullptr, *tail = nullptr, *tmp = nullptr;
	tmp = new st_girl({1, "��ʩ", nullptr});
	head = tail = tmp;

	tmp = new st_girl({5, "����", nullptr});
	tail->next = tmp;
	tail = tmp;

	tmp = new st_girl({3, "���Ѿ�", nullptr});
	tail->next = tmp;
	tail = tmp;

	// ��������
	tmp = head;
	while (tmp != nullptr) {
		cout << tmp->No << " " << tmp->name << endl;
		tmp = tmp->next;
	}

	// �ͷ�����
	while (head != nullptr) {
		tmp = head;
		head = head->next;
		delete tmp;
	}
}
int main() {
	test01();
	system("pause");
	return 0;
}