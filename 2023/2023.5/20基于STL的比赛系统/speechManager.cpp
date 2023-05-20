#include "speechManager.h"


//构造函数
speechManager::speechManager() 
{
	//初始化属性
	this->initSpeech();

	//创建选手
	this->createSpeaker();
}

//创建参赛人员
void speechManager::createSpeaker()
{
	for (int i = 0; i < 12; ++i)
	{
		string name = "选手";
		name += to_string(i + 1);
		Speaker sp;
		sp.setName(name);
		sp.setScore(0, 0);
		sp.setScore(1, 0);
		//将创建的选手编号放入到v1容器中
		this->v1.push_back(i + 1001);
		//将创建的选手编号以及对应的选手，放入到map容器中
		this->m_Speaker.insert(make_pair(i + 1001, sp));
	}
}

//菜单功能
void speechManager::show_Menu() 
{
	cout << "*************************************" << endl;
	cout << "********* 欢迎参加演讲比赛 **********" << endl;
	cout << "********* 1.开始演讲比赛 ************" << endl;
	cout << "********* 2.查看往届记录 ************" << endl;
	cout << "********* 3.清空比赛记录 ************" << endl;
	cout << "********* 0.退出比赛程序 ************" << endl;
	cout << "*************************************" << endl;
	cout << endl;
}

//退出功能
void speechManager::exitSystem() {
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

//初始化容器
void speechManager::initSpeech()
{
	//容器都置空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_Index = 1;
}

//开始比赛
void speechManager::startSpeech()
{
	//第一轮比赛
	//抽签
	this->speechDraw();
	//比赛
	this->speechContest();
	//显示晋级得分
	this->showScore();

	//第二轮比赛
	//抽签
	this->m_Index += 1;
	//比赛
	this->speechContest();
	//显示最终结果
	this->showScore();
	//保存比赛记录
	this->saveRecord();
	cout<< "本届比赛完毕！" << endl;

	//重置比赛
	this->initSpeech();
	this->createSpeaker();

	system("pause");
	system("cls");
}

//抽签
void speechManager::speechDraw()
{
	cout<<"第 << " << this->m_Index << " >> 轮比赛选手抽签结果"<<endl;
	cout<<"--------------------------------------------"<<endl;
	cout<<"抽签后演讲顺序如下："<<endl;
	if (this->m_Index == 1)
	{
		//第一轮比赛
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
		{
			cout << *it << "   ";
		}
		cout << endl;
	}
	else
	{
		//第二轮比赛
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
		{
			cout << *it << "   ";
		}
		cout << endl;
	}
	cout << "------------------------------------------" << endl;
	system("pause");
	cout << endl;
}

//比赛
void speechManager::speechContest()
{
	vector<int> v_src;
	multimap<double, int, greater<double>> tmpM;//暂存选手小组赛成绩
	int num = 0;//选手数量
	cout<< "----------- 第 << " << this->m_Index << " >> 轮比赛正式开始！-----------" << endl;
	cout << endl;
	if (m_Index == 1)
	{
		v_src = v1;//第一轮比赛
	}
	else
	{
		v_src = v2;//第二轮比赛
	}
	for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); ++it)
	{
		//评委打分
		deque<double> tempD;
		for (int i = 0; i < 10; ++i) {
			double score = (rand() % 401 + 600) / 10.0f;
			tempD.push_back(score);
		}
		//去掉最高和最低分，再排序
		sort(tempD.begin(), tempD.end(), greater<double>());
		tempD.pop_front();
		tempD.pop_back();
		//求和再计算平均值
		double sum = accumulate(tempD.begin(), tempD.end(), 0.0f);
		double avg = sum / tempD.size();
		//把选手得分赋值
		this->m_Speaker[*it].setScore(this->m_Index - 1, avg);

		//存放到临时容器
		tmpM.insert(make_pair(avg, *it));
		++num;
		if (num % 6 == 0)
		{
			cout << "--------------- 第 " << num / 6 << " 组选手成绩 ---------------" << endl;
			for (multimap<double, int, greater<double>>::iterator it1 = tmpM.begin(); it1 != tmpM.end(); ++it1)
			{
				cout << "编号：" << it1->second << "姓名：" << left << setw(9) << this->m_Speaker[it1->second].getName() << "成绩：" << this->m_Speaker[it1->second].getScore(this->m_Index - 1) << endl;
			}
			int count = 0;//记录晋级人数，每小组取前三名
			for (multimap<double, int, greater<double>>::iterator it2 = tmpM.begin(); it2 != tmpM.end() && count < 3; ++it2, ++count)
			{
				if (this->m_Index == 1)
				{
					this->v2.push_back(it2->second);
				}
				else
				{
					this->vVictory.push_back(it2->second);
				}
			}
			tmpM.clear();
		}
	}
	cout << "-------------- 第 << " << this->m_Index << " >> 轮比赛结束 --------------" << endl;
	system("pause");
}

//晋级显示得分
void speechManager::showScore()
{
	vector<int> v;
	cout << "-------------- 第 << " << this->m_Index << " >> 轮晋级选手成绩如下 --------------" << endl;
	if (this->m_Index == 1)
	{
		v = this->v2;
	}
	else
	{
		v = this->vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << "编号：" << *it << "   姓名：" << left << setw(9) << this->m_Speaker[*it].getName() << "成绩：" << this->m_Speaker[*it].getScore(this->m_Index - 1) << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_Menu();
}

//保存记录
void speechManager::saveRecord()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::app);
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); ++it)
	{
		//ofs << *it << "," << this->m_Speaker[*it].getScore(1) << ",";
		//ofs << "编号：" << "," << *it << "," << "姓名：" << "," << left << setw(6) << this->m_Speaker[*it].getName() << "," << "成绩：" << "," << this->m_Speaker[*it].getScore(1) << ",   ";
		ofs << "编号：" << *it << "   姓名：" << left << setw(9) << this->m_Speaker[*it].getName() << "成绩：" << this->m_Speaker[*it].getScore(1) << ",   ";
	}
	ofs << endl;
	ofs.close();
	cout << "记录已经保存" << endl;
	this->fileIsEmpty = false;
}

//读取文件
void speechManager::loadRecord()
{
	ifstream ifs;

	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	this->fileIsEmpty = false;
	ifs.putback(ch);
	vector<string> v1;
	while (!ifs.eof())
	{
		int index = 0;
		string s;
		while (ifs >> s)
		{
			v1.push_back(s);
			++index;
			if (index % 3 == 0) {
				//减去v1[3]字符串中的逗号
				//v1[2].erase(v1[2].end() - 1);
				//v1[2].substr(0, v1[2].find(','));
				v1[2].pop_back();
				this->m_vRecord.push_back(v1);//每有一个人的完整数据存一次;每个人信息包含三个字符串
				v1.clear();
			}
		}
	}
	ifs.close();
}

//显示往届记录
void speechManager::showRecord()
{
	if (this->fileIsEmpty) {
		cout << "文件为空或者文件不存在！" << endl;
	}
	else {
		int num = 0;//三个vector元素，组成一届比赛
		for (vector<vector<string>>::iterator it = this->m_vRecord.begin(); it != this->m_vRecord.end(); ++it)
		{
			if (num % 3 == 0) {
				cout << "-------------第 << " << num / 3 + 1 << " >> 届比赛结果---------------" << endl;
			}
			if (num % 3 == 0) {
				cout << "冠军";
			}
			else if (num % 3 == 1) {
				cout << "亚军";
			}
			else {
				cout << "季军";
			}
			for (vector<string>::iterator vit = (*it).begin(); vit != (*it).end(); ++vit)//遍历单个选手的三项数据
			{
				cout << left << setw(14) << *vit;
			}
			cout << endl;
			++num;
		}
		cout << endl;
		this->m_vRecord.clear();
	}
	system("pause");
	system("cls");
}

//清空记录
void speechManager::clearRecord() {
	cout << "确认是否清空往届记录：" << endl;
	cout << "1、确认" << endl;
	cout << "2、取消" << endl;
	int select = 0;
	cin >> select;
	if (select == 2) {
		system("pause");
		system("cls");
		return;
	}
	else if (select == 1) {
		cout << "请输入“确认”再次确认" << endl;
		string ret;
		cin >> ret;
		if (ret != "确认") {
			system("pause");
			system("cls");
			return;
		}
		else if (ret == "确认") {
			ofstream ofs(FILENAME, ios::trunc);//如果文件存在，会直接删除再创建
			ofs.close();
			this->initSpeech();
			this->createSpeaker();
			cout << "清空成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	else {
		cout << "输入错误" << endl;
		system("pause");
		system("cls");
	}
}

//析构函数
speechManager::~speechManager() 
{
	
}