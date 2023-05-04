#include <iostream>
using namespace std;
#include <string>
#include <map>
#include <vector>
#include <ctime>
#include <iomanip>

//����Ա����
class Worker{
public:
    string m_name;
    //int m_age;
    int m_salary;
};

//����Ա������
void createWorker(vector<Worker>& vWorker){
    //string nameSeed = "ABCDEFGHIJ";
    for(int i = 0; i < 10; i++){
        Worker worker;
        worker.m_name = "Ա��";
        worker.m_name += to_string(i+1);
        worker.m_salary = rand() % 10001 + 10000;
        vWorker.push_back(worker);
    }
}

//��ӡԱ������
void printVec(vector<Worker>& v){
    for(vector<Worker>::iterator it = v.begin(); it != v.end(); ++it){
        cout << "������" << left << setw(8) << it->m_name << "���ʣ�" << it->m_salary << endl;
    }//setw()����������, left�����;��Ҫiomanipͷ�ļ�
}

//Ա���������
void setGroup(vector<Worker>& v, multimap<int, Worker>& m){
    for(vector<Worker>::iterator it = v.begin(); it != v.end(); ++it){
        int depId = rand() % 3 + 1;
        m.insert(make_pair(depId, *it));
    }
}

//��ӡ������Ա��
void printMul(multimap<int, Worker>& m){
    cout << "1.�߻����ţ�" << endl;
    multimap<int, Worker>::iterator pos = m.find(1);
    int count = m.count(1);
    int index = 0;//������������ʱ������index == countʱ������ѭ��
    for(pos = m.find(1); index < count; ++pos, ++index){
        cout << "������" << left << setw(8) << pos->second.m_name << "���ʣ�" << pos->second.m_salary << endl;
    }
    cout << "2.�з����ţ�" << endl;
    //pos = m.find(2);
    count = m.count(2);
    index = 0;
    for(pos = m.find(2); index < count; ++pos, ++index){
        cout << "������" << left << setw(8) << pos->second.m_name << "���ʣ�" << pos->second.m_salary << endl;
    }
    cout << "3.�������ţ�" << endl;
    //pos = m.find(3);
    count = m.count(3);
    index = 0;
    for(pos = m.find(3); index < count; ++pos, ++index){
        cout << "������" << left << setw(8) << pos->second.m_name << "���ʣ�" << pos->second.m_salary << endl;
    }
}
void test01(){
    vector<Worker> vWorker;
    createWorker(vWorker);
    //printVec(vWorker);
    multimap<int, Worker> mWorker;
    setGroup(vWorker, mWorker);
    printMul(mWorker);
}//multimap����
int main(){
    srand((unsigned int)time(NULL));//��Ҫctimeͷ�ļ�
    test01();
    system("pause");
    return 0;
}