class Cube
{
public:
	void setL(float L)
	{
		m_L = L;
	}
	float getL()
	{
		return m_L;
	}
	void setW(float W)
	{
		m_W = W;
	}
	float getW()
	{
		return m_W;
	}
	void setH(float H)
	{
		m_H = H;
	}
	float getH()
	{
		return m_H;
	}
	float calculateS()
	{
		return (m_L * m_W + m_L * m_H + m_W * m_H) * 2;
	}
	float calculateV()
	{
		return m_L * m_W * m_H;
	}
	bool isSameClass(Cube& c)//用类函数比较，只需要传一个对象，传入的对象和对象自己比较
	{
		if (m_L == c.getL() && m_W == c.getW() && m_H == c.getH())
			return true;
		else
			return false;
	}
private:
	float m_L;
	float m_W;
	float m_H;
};
bool isSame(Cube& c1, Cube& c2)//全局函数比较
{
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
		return true;
	else
		return false;
}
int main()
{
	Cube c1;
	c1.setL(2);
	c1.setW(2);
	c1.setH(2);
	cout << "立方体的面积： " << c1.calculateS() << endl;
	cout << "立方体的体积： " << c1.calculateV() << endl;
	Cube c2;
	c2.setL(2);
	c2.setW(2);
	c2.setH(2);
	bool ret1 = c1.isSameClass(c2);//类函数比较时，只用传一个参数
	if (ret1)
		cout << "相同" << endl;
	else
		cout << "不同" << endl;
	bool ret = isSame(c1, c2);
	if (ret)
		cout << "相同" << endl;
	else
		cout << "不同" << endl;
	return 0;
}