#define _CRT_SECURE_NO_WARINGS
#include <iostream>
using namespace std;
#include <string>

//抽象类电脑配件
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
		m_cpu = cpu;//电脑配件
		m_gpu = gpu;
		m_ram = ram;
	}
	void work()
	{
		m_cpu->calculate();//封装接口让配件运行
		m_gpu->display();
		m_ram->storage();
	}
	~Computer()//不是继承的父子关系，所以不需要虚析构来释放
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
//抽象类子类
class IntelCPU :public CPU
{
public:
	void calculate()
	{
		cout << "Intel的Cup开始运算了！" << endl;
	}
};
class IntelGPU :public GPU
{
public:
	void display()
	{
		cout << "Intel的Gup开始显示了！" << endl;
	}
};
class IntelMemory :public Memory
{
public:
	void storage()
	{
		cout << "Intel的内存开始存储了！" << endl;
	}
};
class HuaweiCPU :public CPU
{
public:
	void calculate()
	{
		cout << "Huawei的Cup开始运算了！" << endl;
	}
};
class HuaweiGPU :public GPU
{
public:
	void display()
	{
		cout << "Huawei的Gup开始显示了！" << endl;
	}
};
class HuaweiMemory :public Memory
{
public:
	void storage()
	{
		cout << "Huawei的内存开始存储了！" << endl;
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