#include <iostream>
using namespace std;
#include <string>
#include <map>
#include <vector>
#include <ctime>
#include <iomanip>

//创建员工类
class Worker{
public:
    string m_name;
    //int m_age;
    int m_salary;
};

//创建员工数组
void createWorker(vector<Worker>& vWorker){
    //string nameSeed = "ABCDEFGHIJ";
    for(int i = 0; i < 10; i++){
        Worker worker;
        worker.m_name = "员工";
        worker.m_name += to_string(i+1);
        worker.m_salary = rand() % 10001 + 10000;
        vWorker.push_back(worker);
    }
}

//打印员工数组
void printVec(vector<Worker>& v){
    for(vector<Worker>::iterator it = v.begin(); it != v.end(); ++it){
        cout << "姓名：" << left << setw(8) << it->m_name << "工资：" << it->m_salary << endl;
    }//setw()设置输出宽度, left左对齐;需要iomanip头文件
}

//员工随机分组
void setGroup(vector<Worker>& v, multimap<int, Worker>& m){
    for(vector<Worker>::iterator it = v.begin(); it != v.end(); ++it){
        int depId = rand() % 3 + 1;
        m.insert(make_pair(depId, *it));
    }
}

//打印分组后的员工
void printMul(multimap<int, Worker>& m){
    cout << "1.策划部门：" << endl;
    multimap<int, Worker>::iterator pos = m.find(1);
    int count = m.count(1);
    int index = 0;//到结束迭代器时，或者index == count时，结束循环
    for(pos = m.find(1); index < count; ++pos, ++index){
        cout << "姓名：" << left << setw(8) << pos->second.m_name << "工资：" << pos->second.m_salary << endl;
    }
    cout << "2.研发部门：" << endl;
    //pos = m.find(2);
    count = m.count(2);
    index = 0;
    for(pos = m.find(2); index < count; ++pos, ++index){
        cout << "姓名：" << left << setw(8) << pos->second.m_name << "工资：" << pos->second.m_salary << endl;
    }
    cout << "3.美术部门：" << endl;
    //pos = m.find(3);
    count = m.count(3);
    index = 0;
    for(pos = m.find(3); index < count; ++pos, ++index){
        cout << "姓名：" << left << setw(8) << pos->second.m_name << "工资：" << pos->second.m_salary << endl;
    }
}
void test01(){
    vector<Worker> vWorker;
    createWorker(vWorker);
    //printVec(vWorker);
    multimap<int, Worker> mWorker;
    setGroup(vWorker, mWorker);
    printMul(mWorker);
}//multimap容器
int main(){
    srand((unsigned int)time(NULL));//需要ctime头文件
    test01();
    system("pause");
    return 0;
}