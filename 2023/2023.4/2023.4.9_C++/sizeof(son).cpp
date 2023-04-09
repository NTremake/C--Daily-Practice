class father
{
public:
	int A;
protected:
	int B;
private:
	int C;
};
class son1 :public father
{
public:
	int D;
};
void test1()
{
	cout << sizeof(son1) << endl;//子类的大小是父类加子类16
}
int main()
{
	test1();
	system("pause");
	return 0;
}