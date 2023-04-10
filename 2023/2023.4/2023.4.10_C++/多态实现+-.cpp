class calculator
{
public:
	virtual int getResult()
	{
		return 0;
	}
	int m_num1;
	int m_num2;
};
class addCalculator :public calculator//加法
{
public:
	int getResult()
	{
		return m_num1 + m_num2;
	}
};
class subCalculator :public calculator//减法
{
public:
	int getResult()
	{
		return m_num1 - m_num2;
	}
};
class multCalculator :public calculator//乘法
{
public:
	int getResult()
	{
		return m_num1 * m_num2;
	}
};
//开闭原则：多扩展开放，对修改关闭。
//多态的好处：1、组织结构清晰。 2、可读性强。 3、对于前期和后期的扩展和维护方便
void test1()
{
	calculator* abc = new addCalculator;
	abc->m_num1 = 10;
	abc->m_num2 = 10;
	cout << abc->m_num1 << "+" << abc->m_num2 << "=" << abc->getResult() << endl;
	delete abc;
	abc = new subCalculator;
	abc->m_num1 = 10;
	abc->m_num2 = 5;
	cout << abc->m_num1 << "-" << abc->m_num2 << "=" << abc->getResult() << endl;
	delete abc;
	abc = new multCalculator;
	abc->m_num1 = 10;
	abc->m_num2 = 10;
	cout << abc->m_num1 << "*" << abc->m_num2 << "=" << abc->getResult() << endl;
	delete abc;
}
int main()
{
	test1();
	system("pause");
	return 0;
}