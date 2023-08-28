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
	condition_variable m_cond;// 条件变量，不能拷贝和赋值
	queue<string, deque<string>> m_que;// 缓存队列，底层容器用deque(第二个参数是指定底层容器类型)
public:
	void incache(int num)
	{
		lock_guard<mutex> lock(m_mtx);// 申请加锁
		for (int i = 0; i < num; i++)
		{
			string str = "数据" + to_string(i + 1);
			m_que.push(str);
		}
		//m_cond.notify_one();// 唤醒一个被当前条件变量阻塞的线程
		m_cond.notify_all();// 唤醒所有线程，生产多个数据时，这个效率更高;但是数据不够的时候，线程可能被虚假唤醒
	}
	void outcache()
	{
		while (true)
		{
			string str;// 互斥锁的作用域越小，效率越高
			unique_lock<mutex> lock(m_mtx);// 互斥锁转换成unique_lock<mutex>类型，一般搭配condition_variable使用
			while (m_que.empty())// 如果缓存为空，就需要进入循环等待（不能用if）
			{
				// 1)解开互斥锁；2)阻塞，等待被唤醒；3)给互斥锁加锁
				m_cond.wait(lock);// 等待生产者的唤醒
				//cout << "线程：" << this_thread::get_id() << "被唤醒了" << endl;
			}
			//m_cond.wait(lock, [this] {return !m_que.empty();});
			str = m_que.front();// 元素出队
			m_que.pop();
			cout << "线程：" << this_thread::get_id() << "，" << str << endl;
			lock.unlock();// unique_lock也可以手动解锁

			this_thread::sleep_for(chrono::milliseconds(1));// 假设处理数据需要1毫秒
		}
	}
};// condition_variable条件变量，生产者消费者模型
int main()
{
	AA aa;
	thread t1(&AA::outcache, &aa);
	thread t2(&AA::outcache, &aa);
	thread t3(&AA::outcache, &aa);

	this_thread::sleep_for(chrono::seconds(1));
	aa.incache(2);// 生产2个数据
	this_thread::sleep_for(chrono::seconds(2));
	aa.incache(5);// 生产5个数据

	t1.join();
	t2.join();
	t3.join();
}