#include "speechManager.h"


//���캯��
speechManager::speechManager() 
{
	//��ʼ������
	this->initSpeech();

	//����ѡ��
	this->createSpeaker();
}

//����������Ա
void speechManager::createSpeaker()
{
	for (int i = 0; i < 12; ++i)
	{
		string name = "ѡ��";
		name += to_string(i + 1);
		Speaker sp;
		sp.setName(name);
		sp.setScore(0, 0);
		sp.setScore(1, 0);
		//��������ѡ�ֱ�ŷ��뵽v1������
		this->v1.push_back(i + 1001);
		//��������ѡ�ֱ���Լ���Ӧ��ѡ�֣����뵽map������
		this->m_Speaker.insert(make_pair(i + 1001, sp));
	}
}

//�˵�����
void speechManager::show_Menu() 
{
	cout << "*************************************" << endl;
	cout << "********* ��ӭ�μ��ݽ����� **********" << endl;
	cout << "********* 1.��ʼ�ݽ����� ************" << endl;
	cout << "********* 2.�鿴�����¼ ************" << endl;
	cout << "********* 3.��ձ�����¼ ************" << endl;
	cout << "********* 0.�˳��������� ************" << endl;
	cout << "*************************************" << endl;
	cout << endl;
}

//�˳�����
void speechManager::exitSystem() {
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

//��ʼ������
void speechManager::initSpeech()
{
	//�������ÿ�
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_Index = 1;
}

//��ʼ����
void speechManager::startSpeech()
{
	//��һ�ֱ���
	//��ǩ
	this->speechDraw();
	//����
	this->speechContest();
	//��ʾ�����÷�
	this->showScore();

	//�ڶ��ֱ���
	//��ǩ
	this->m_Index += 1;
	//����
	this->speechContest();
	//��ʾ���ս��
	this->showScore();
	//���������¼
	this->saveRecord();
	cout<< "���������ϣ�" << endl;

	//���ñ���
	this->initSpeech();
	this->createSpeaker();

	system("pause");
	system("cls");
}

//��ǩ
void speechManager::speechDraw()
{
	cout<<"�� << " << this->m_Index << " >> �ֱ���ѡ�ֳ�ǩ���"<<endl;
	cout<<"--------------------------------------------"<<endl;
	cout<<"��ǩ���ݽ�˳�����£�"<<endl;
	if (this->m_Index == 1)
	{
		//��һ�ֱ���
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
		{
			cout << *it << "   ";
		}
		cout << endl;
	}
	else
	{
		//�ڶ��ֱ���
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

//����
void speechManager::speechContest()
{
	vector<int> v_src;
	multimap<double, int, greater<double>> tmpM;//�ݴ�ѡ��С�����ɼ�
	int num = 0;//ѡ������
	cout<< "----------- �� << " << this->m_Index << " >> �ֱ�����ʽ��ʼ��-----------" << endl;
	cout << endl;
	if (m_Index == 1)
	{
		v_src = v1;//��һ�ֱ���
	}
	else
	{
		v_src = v2;//�ڶ��ֱ���
	}
	for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); ++it)
	{
		//��ί���
		deque<double> tempD;
		for (int i = 0; i < 10; ++i) {
			double score = (rand() % 401 + 600) / 10.0f;
			tempD.push_back(score);
		}
		//ȥ����ߺ���ͷ֣�������
		sort(tempD.begin(), tempD.end(), greater<double>());
		tempD.pop_front();
		tempD.pop_back();
		//����ټ���ƽ��ֵ
		double sum = accumulate(tempD.begin(), tempD.end(), 0.0f);
		double avg = sum / tempD.size();
		//��ѡ�ֵ÷ָ�ֵ
		this->m_Speaker[*it].setScore(this->m_Index - 1, avg);

		//��ŵ���ʱ����
		tmpM.insert(make_pair(avg, *it));
		++num;
		if (num % 6 == 0)
		{
			cout << "--------------- �� " << num / 6 << " ��ѡ�ֳɼ� ---------------" << endl;
			for (multimap<double, int, greater<double>>::iterator it1 = tmpM.begin(); it1 != tmpM.end(); ++it1)
			{
				cout << "��ţ�" << it1->second << "������" << left << setw(9) << this->m_Speaker[it1->second].getName() << "�ɼ���" << this->m_Speaker[it1->second].getScore(this->m_Index - 1) << endl;
			}
			int count = 0;//��¼����������ÿС��ȡǰ����
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
	cout << "-------------- �� << " << this->m_Index << " >> �ֱ������� --------------" << endl;
	system("pause");
}

//������ʾ�÷�
void speechManager::showScore()
{
	vector<int> v;
	cout << "-------------- �� << " << this->m_Index << " >> �ֽ���ѡ�ֳɼ����� --------------" << endl;
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
		cout << "��ţ�" << *it << "   ������" << left << setw(9) << this->m_Speaker[*it].getName() << "�ɼ���" << this->m_Speaker[*it].getScore(this->m_Index - 1) << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_Menu();
}

//�����¼
void speechManager::saveRecord()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::app);
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); ++it)
	{
		//ofs << *it << "," << this->m_Speaker[*it].getScore(1) << ",";
		//ofs << "��ţ�" << "," << *it << "," << "������" << "," << left << setw(6) << this->m_Speaker[*it].getName() << "," << "�ɼ���" << "," << this->m_Speaker[*it].getScore(1) << ",   ";
		ofs << "��ţ�" << *it << "   ������" << left << setw(9) << this->m_Speaker[*it].getName() << "�ɼ���" << this->m_Speaker[*it].getScore(1) << ",   ";
	}
	ofs << endl;
	ofs.close();
	cout << "��¼�Ѿ�����" << endl;
	this->fileIsEmpty = false;
}

//��ȡ�ļ�
void speechManager::loadRecord()
{
	ifstream ifs;

	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
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
				//��ȥv1[3]�ַ����еĶ���
				//v1[2].erase(v1[2].end() - 1);
				//v1[2].substr(0, v1[2].find(','));
				v1[2].pop_back();
				this->m_vRecord.push_back(v1);//ÿ��һ���˵��������ݴ�һ��;ÿ������Ϣ���������ַ���
				v1.clear();
			}
		}
	}
	ifs.close();
}

//��ʾ�����¼
void speechManager::showRecord()
{
	if (this->fileIsEmpty) {
		cout << "�ļ�Ϊ�ջ����ļ������ڣ�" << endl;
	}
	else {
		int num = 0;//����vectorԪ�أ����һ�����
		for (vector<vector<string>>::iterator it = this->m_vRecord.begin(); it != this->m_vRecord.end(); ++it)
		{
			if (num % 3 == 0) {
				cout << "-------------�� << " << num / 3 + 1 << " >> ��������---------------" << endl;
			}
			if (num % 3 == 0) {
				cout << "�ھ�";
			}
			else if (num % 3 == 1) {
				cout << "�Ǿ�";
			}
			else {
				cout << "����";
			}
			for (vector<string>::iterator vit = (*it).begin(); vit != (*it).end(); ++vit)//��������ѡ�ֵ���������
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

//��ռ�¼
void speechManager::clearRecord() {
	cout << "ȷ���Ƿ���������¼��" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2��ȡ��" << endl;
	int select = 0;
	cin >> select;
	if (select == 2) {
		system("pause");
		system("cls");
		return;
	}
	else if (select == 1) {
		cout << "�����롰ȷ�ϡ��ٴ�ȷ��" << endl;
		string ret;
		cin >> ret;
		if (ret != "ȷ��") {
			system("pause");
			system("cls");
			return;
		}
		else if (ret == "ȷ��") {
			ofstream ofs(FILENAME, ios::trunc);//����ļ����ڣ���ֱ��ɾ���ٴ���
			ofs.close();
			this->initSpeech();
			this->createSpeaker();
			cout << "��ճɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	else {
		cout << "�������" << endl;
		system("pause");
		system("cls");
	}
}

//��������
speechManager::~speechManager() 
{
	
}