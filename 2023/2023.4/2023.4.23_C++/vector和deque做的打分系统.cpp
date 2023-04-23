#include <string>
#include <vector>
#include <deque>
#include <algorithm>
class Person
{
public:
	Person(string name,int score) {
		this->m_Name = name;
		this->m_Score = score;
	}
	string m_Name;
	int m_Score;
};
void creatPerson(vector<Person>& v)
{//给每个类命名
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; ++i) {
		string name = "选手";
		name += nameSeed[i];
		int score = 0;
		Person p(name, score);
		v.push_back(p);
	}
}
void setScore(vector<Person>& v) 
{//给每个类添加分数
	for (vector<Person>::iterator it = v.begin(); it != v.end();++it) {
		deque<int>d1;//把分数放进deque容器
		for (int i = 0; i < 10; ++i) {
			int score = rand() % 41 + 60;
			d1.push_back(score);
		}
		sort(d1.begin(), d1.end());
		d1.pop_front();//排序后去除高低分
		d1.pop_back();
		for (deque<int>::iterator dit1 = d1.begin(); dit1 != d1.end(); ++dit1) {
			cout << *dit1 << "  ";
		}//查看每个打分
		cout << endl;
		int sum = 0;
		for (deque<int>::iterator dit = d1.begin(); dit != d1.end(); ++dit) {
			sum += *dit;//求和
		}
		int avg = sum / d1.size();//求平均数
		it->m_Score = avg;//算出平均数后赋值
	}
}
void myPrintf(vector<Person>& v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); ++it){
		cout << "姓名：" << it->m_Name << "  分数：" << it->m_Score << endl;
	}
}
int main(){
	srand((unsigned int)time(NULL));
	vector<Person>v1;//用vector存放类
	creatPerson(v1);
	setScore(v1);
	myPrintf(v1);
	system("pause");
	return 0;
}