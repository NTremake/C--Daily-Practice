class father
{
public:
	int A;
protected:
	int B;
private:
	int C;//父类的私有权限，子类都不能访问
};
class son1 :public father
{
	void visit()
	{
		A = 10;//公共继承后，是公共权限
		B = 10;//公共继承后，是保护权限
		/*C = 10;*///公共继承后，是保护权限，但还是不能访问
	}
};
class son2 :protected father
{
	void visit()
	{
		A = 10;//保护继承后，都是保护权限
		B = 10;
		/*C = 10;*/
	}
};
class son3 :private father
{
	void visit()
	{
		A = 10;//私有继承后，都是私有权限
		B = 10;
		/*C = 10;*/
	}
};
class grandson :public son3
{
	void visit()
	{
		/*A = 10;//继承子类的私有权限后，也不能访问
		B = 10;*/
	}
};
void test1()
{
	son2 s1;
	/*s1.A = 10;*///子类在保护继承后，A在父类中即使是公共权限，在子类中也不能访问
}
int main()
{
	test1();
	system("pause");
	return 0;
}