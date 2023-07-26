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
	tmp = new st_girl({1, "西施", nullptr});
	head = tail = tmp;

	tmp = new st_girl({5, "貂蝉", nullptr});
	tail->next = tmp;
	tail = tmp;

	tmp = new st_girl({3, "王昭君", nullptr});
	tail->next = tmp;
	tail = tmp;

	// 遍历链表
	tmp = head;
	while (tmp != nullptr) {
		cout << tmp->No << " " << tmp->name << endl;
		tmp = tmp->next;
	}

	// 释放链表
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