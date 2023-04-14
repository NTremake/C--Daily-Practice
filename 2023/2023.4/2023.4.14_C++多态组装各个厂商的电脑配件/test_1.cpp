#define _CRT_SECURE_NO_WARINGS
#include <iostream>
using namespace std;
#include <string>

//������������
class CPU
{
public:
	virtual void calculate() = 0;
};
class GPU
{
public:
	virtual void display() = 0;
};
class Memory
{
public:
	virtual void storage() = 0;
};

class Computer
{
public:
	Computer(CPU* cpu, GPU* gpu, Memory* ram)
	{
		m_cpu = cpu;//�������
		m_gpu = gpu;
		m_ram = ram;
	}
	void work()
	{
		m_cpu->calculate();//��װ�ӿ����������
		m_gpu->display();
		m_ram->storage();
	}
	~Computer()//���Ǽ̳еĸ��ӹ�ϵ�����Բ���Ҫ���������ͷ�
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_gpu != NULL)
		{
			delete m_gpu;
			m_gpu = NULL;
		}
		if (m_ram != NULL)
		{
			delete m_ram;
			m_ram = NULL;
		}
	}
private:
	CPU* m_cpu;
	GPU* m_gpu;
	Memory* m_ram;
};
//����������
class IntelCPU :public CPU
{
public:
	void calculate()
	{
		cout << "Intel��Cup��ʼ�����ˣ�" << endl;
	}
};
class IntelGPU :public GPU
{
public:
	void display()
	{
		cout << "Intel��Gup��ʼ��ʾ�ˣ�" << endl;
	}
};
class IntelMemory :public Memory
{
public:
	void storage()
	{
		cout << "Intel���ڴ濪ʼ�洢�ˣ�" << endl;
	}
};
class HuaweiCPU :public CPU
{
public:
	void calculate()
	{
		cout << "Huawei��Cup��ʼ�����ˣ�" << endl;
	}
};
class HuaweiGPU :public GPU
{
public:
	void display()
	{
		cout << "Huawei��Gup��ʼ��ʾ�ˣ�" << endl;
	}
};
class HuaweiMemory :public Memory
{
public:
	void storage()
	{
		cout << "Huawei���ڴ濪ʼ�洢�ˣ�" << endl;
	}
};
void test1()
{
	CPU* Intelcpu = new IntelCPU;
	GPU* Intelgpu = new IntelGPU;
	Memory* Intelram = new IntelMemory;
	Computer* computer1 = new Computer(Intelcpu, Intelgpu, Intelram);
	computer1->work();
	delete computer1;
	cout << "------------------------" << endl;
	Computer* computer2 = new Computer(new HuaweiCPU, new HuaweiGPU, new HuaweiMemory);
	computer2->work();
	delete computer2;
	cout << "--------------------------" << endl;
	Computer* computer3 = new Computer(new IntelCPU, new HuaweiGPU, new HuaweiMemory);
	computer3->work();
	delete computer3;
}
int main()
{
	test1();
	system("pause");
	return 0;
}