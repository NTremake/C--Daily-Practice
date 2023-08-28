#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <deque>
#include <string>
using namespace std;

static int id = 0;
class AA
{
private:
	mutex m_mtx;
	condition_variable m_cond;// �������������ܿ����͸�ֵ
	queue<string, deque<string>> m_que;// ������У��ײ�������deque(�ڶ���������ָ���ײ���������)
public:
	void incache(int num)
	{
		lock_guard<mutex> lock(m_mtx);// �������
		for (int i = 0; i < num; i++)
		{
			string str = "����" + to_string(i + 1);
			m_que.push(str);
		}
		//m_cond.notify_one();// ����һ������ǰ���������������߳�
		m_cond.notify_all();// ���������̣߳������������ʱ�����Ч�ʸ���;�������ݲ�����ʱ���߳̿��ܱ���ٻ���
	}
	void outcache()
	{
		while (true)
		{
			string str;// ��������������ԽС��Ч��Խ��
			unique_lock<mutex> lock(m_mtx);// ������ת����unique_lock<mutex>���ͣ�һ�����condition_variableʹ��
			while (m_que.empty())// �������Ϊ�գ�����Ҫ����ѭ���ȴ���������if��
			{
				// 1)�⿪��������2)�������ȴ������ѣ�3)������������
				m_cond.wait(lock);// �ȴ������ߵĻ���
				//cout << "�̣߳�" << this_thread::get_id() << "��������" << endl;
			}
			//m_cond.wait(lock, [this] {return !m_que.empty();});
			str = m_que.front();// Ԫ�س���
			m_que.pop();
			cout << "�̣߳�" << this_thread::get_id() << "��" << str << endl;
			lock.unlock();// unique_lockҲ�����ֶ�����

			this_thread::sleep_for(chrono::milliseconds(1));// ���账��������Ҫ1����
		}
	}
};// condition_variable����������������������ģ��
int main()
{
	AA aa;
	thread t1(&AA::outcache, &aa);
	thread t2(&AA::outcache, &aa);
	thread t3(&AA::outcache, &aa);

	this_thread::sleep_for(chrono::seconds(1));
	aa.incache(2);// ����2������
	this_thread::sleep_for(chrono::seconds(2));
	aa.incache(5);// ����5������

	t1.join();
	t2.join();
	t3.join();
}