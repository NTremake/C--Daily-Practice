#define _CRT_SECURE_NO_WARINGS
#include "WorkerManager.h"

//��ʼ��
workerManager::workerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())//�ļ������ڵ����
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		this->m_EmpNum = 0;//��ʼ������
		this->m_EmpArray = NULL;
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;//��ifs�ȶ�һ���ַ������ж�����ַ��Ƿ�Ϊ�ļ�������
	if (ifs.eof())//�ļ����ڣ�������Ϊ�յ����
	{
		cout << "�ļ�����Ϊ�գ�" << endl;
		this->m_EmpNum = 0;//��ʼ������
		this->m_EmpArray = NULL;
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}

	this->m_EmpNum = this->get_empNum();//�ļ��������ݵ����
	cout << "�ļ��е�ְ������Ϊ��" << this->m_EmpNum << endl;
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();

	//for (int i = 0; i < this->m_EmpNum; i++)//���Դ���
	//{
	//	cout << "ְ����ţ�" << this->m_EmpArray[i]->m_id
	//		<< "   ְ��������" << this->m_EmpArray[i]->m_name
	//		<< "   ְ����λ��" << this->m_EmpArray[i]->m_deptId << endl;
	//	/*this->m_EmpArray[a]->showInfo();*/
	//}
}

//�˵�
void workerManager::showMenu()
{
	cout << "****************************************" << endl;
	cout << "******** ��ӭʹ��ְ������ϵͳ�� ********" << endl;
	cout << "************ 0.�˳�������� ************" << endl;
	cout << "************ 1.����ְ����Ϣ ************" << endl;
	cout << "************ 2.��ʾְ����Ϣ ************" << endl;
	cout << "************ 3.ɾ����ְְ�� ************" << endl;
	cout << "************ 4.�޸�ְ����Ϣ ************" << endl;
	cout << "************ 5.����ְ����Ϣ ************" << endl;
	cout << "************ 6.���ձ������ ************" << endl;
	cout << "************ 7.��������ĵ� ************" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}

//�˳�����
void workerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

//�����ְ��
void workerManager::add_Emp()
{
	cout << "��������Ҫ��ӵ�ְ��������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		
		Worker* worker = NULL;//worker��newspace�����еĵ���ְ��
		int newSize = this->m_EmpNum + addNum;//��ְ������=ԭְ����+����ӵ�ְ����
		Worker** newSpace = new Worker* [newSize * sizeof(worker)];//new arr[10]��������ָ�롣[newSize*sizeof(worker)]

		if (this->m_EmpArray != NULL)//�����Ϊ�գ�����Ҫ�ȰѾ������ݴ浽������
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];//�Ѿ������ݴ���������
			}
		}
		for (int i = 0; i < addNum; i++)//������ӵ�Ա����ֵ
		{
			int id;
			string name;
			int dSelect;
			cout << "�������" << i + 1 << "����ְ���ı�ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ����������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1������Ա��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;


			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				cout << "����������������룡" << endl;
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;//����Ա����ӵ�������
		}
		delete[] m_EmpArray;//��վ�����
		this->m_EmpArray = newSpace;//���¾�����ռ�
		this->m_EmpNum = newSize;//���¾ɵ�Ա������
		this->m_fileIsEmpty = false;//�����ļ���Ϊ�յı�־
		this->save();
		cout << "�ɹ����" << addNum << "����ְ����" << endl;
	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}

//�����ļ�
void workerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << "   "
			<< this->m_EmpArray[i]->m_name << "   "
			<< this->m_EmpArray[i]->m_deptId << endl;
	}
	ofs.close();
}

//��ȡ�ļ��е�����
int workerManager::get_empNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	ifs.close();
	return num;
}

//��ʼ��ְ����Ϣ
void workerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;
		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			worker = new Manager(id, name, did);
		}
		else
		{
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//��ʾԱ����Ϣ����
void workerManager::show_Emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ�գ�" << endl;
	}
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		this->m_EmpArray[i]->showInfo();
	}
	system("pause");
	system("cls");
}

//ɾ��ְ��
void workerManager::del_Emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ�գ�" << endl;
	}
	else
	{
		int id = 0;
		cout << "������Ҫɾ����ְ����ţ�" << endl;
		cin >> id;
		int index = this->isExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			if (this->m_EmpNum == 0)
			{
				this->m_fileIsEmpty = true;
			}
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "δ�ҵ���ְ����" << endl;
		}
		system("pause");
		system("cls");
	}
}

//�ж�ְ���Ƿ���ڣ������������е�λ��
int workerManager::isExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (id == this->m_EmpArray[i]->m_id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//�޸�ְ����Ϣ
void workerManager::mod_Emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸ĵ�ְ����ţ�" << endl;
		int id;
		cin >> id;
		int ret = this->isExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "�鵽��" << id << "��ְ������Ϣ���������ְ�����±�ţ�" << endl;
			cin >> newId;
			cout << "�������ְ����������" << endl;
			cin >> newName;
			cout << "�������ְ����λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				cout << "����������������룡" << endl;
				break;
			}
			this->m_EmpArray[ret] = worker;
			this->save();
			cout << "�޸ĳɹ���" << endl;
		}
		else
		{
			cout << "δ�ҵ���ְ����Ϣ��" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void workerManager::find_Emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��߲����ڣ�" << endl;
	}
	else
	{
		cout << "��ѡ����ҷ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2����ְ����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "������ְ����ţ�" << endl;
			int id = 0;
			cin >> id;
			int ret = this->isExist(id);
			if (ret != -1)
			{
				cout << "��Ա����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "���޴��ˣ�" << endl;
			}
		}
		else if (select == 2)
		{
			cout << "������ְ��������" << endl;
			string name = "";
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_name == name)
				{
					cout << "���ҳɹ�����" << this->m_EmpArray[i]->m_id << "��ְ����Ϣ���£�" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "���޴��ˣ�" << endl;
			}
		}
		else
		{
			cout << "����������������룡" << endl;
		}
	}
	system("pause");
	system("cls");
}

//ְ������
void workerManager::sort_Emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��ļ������ڣ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1���������������" << endl;
		cout << "2������Ž�������" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (this->m_EmpArray[minOrMax]->m_id > this->m_EmpArray[j]->m_id)
					{
						minOrMax = j;
					}
				}
				else if (select == 2)
				{
					if (this->m_EmpArray[minOrMax]->m_id < this->m_EmpArray[j]->m_id)
					{
						minOrMax = j;
					}
				}
				else
				{
					cout << "���޴��ˣ�" << endl;
				}
			}
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		this->save();
		cout << "����ɹ���������Ϊ��" << endl;
		this->show_Emp();
	}
}

//����ļ�
void workerManager::clean_File()
{
	cout << "ȷ�����ְ����Ϣ��" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2��ȡ��" << endl;
	int select = 0;
	cin >> select;
	if(select == 1)
	{
		while (select == 1)
		{
			cout << "�����롰ȷ����ա��ĸ����ٴ�ȷ�ϣ�" << endl;
			string ret = "";
			cin >> ret;
			string str = "ȷ�����";
			if (ret == str)
			{
				ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ����½�
				ofs.close();
				if (this->m_EmpArray != NULL)
				{
					for (int i = 0; i < this->m_EmpNum; i++)
					{
						delete this->m_EmpArray[i];
						this->m_EmpArray[i] = NULL;
					}
					delete[] this->m_EmpArray;
					this->m_EmpArray = NULL;
					this->m_EmpNum = 0;
					this->m_fileIsEmpty = true;
					cout << "��ճɹ���" << endl;
					break;
				}
				break;
			}
			else
				break;
		}
	}
	system("pause");
	system("cls");
}

workerManager::~workerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			delete this->m_EmpArray[i];
			this->m_EmpArray[i] = NULL;
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_fileIsEmpty = true;
	}
}