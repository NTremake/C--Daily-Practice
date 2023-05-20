#pragma once
#include <iostream>
using namespace std;

class Speaker 
{
public:
	void setName(string name)
	{
		this->m_Name = name;
	}
	string getName()
	{
		return this->m_Name;
	}
	void setScore(int index, double score)
	{
		this->m_Score[index] = score;
	}
	float getScore(int index)
	{
		return this->m_Score[index];
	}
private:
	string m_Name; //ĞÕÃû
	float m_Score[2]; //·ÖÊı
};