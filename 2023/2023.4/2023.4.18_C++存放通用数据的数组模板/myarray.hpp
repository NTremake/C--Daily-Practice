#pragma once
#include <iostream>
using namespace std;
#include <string>

template<class T>
class myArray
{
public:
	//构造函数
	myArray(int capacity)
	{
		/*cout << "构造函数调用" << endl;*/
		this->capacity = capacity;
		this->m_size = 0;
		this->pAddress = new T[this->capacity];
	}

	//拷贝构造
	myArray(const myArray& arr)
	{
		/*cout << "拷贝构造函数调用" << endl;*/
		this->capacity = arr.capacity;
		this->m_size = arr.m_size;
		this->pAddress = new T[arr.capacity * sizeof(T)];
		for (int i = 0; i < this->m_size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//等号的重载
	myArray& operator=(const myArray& arr)
	{
	//cout << "operator=函数调用" << endl;
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->capacity = 0;
			this->m_size = 0;
		}
		this->capacity = arr.capacity;
		this->m_size = arr.m_size;
		this->pAddress = new T[arr.capacity * sizeof(T)];
		for (int i = 0; i < this->m_size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//尾插法
	void Push_Back(const T& value1)
	{
		if (this->capacity == this->m_size)
		{
			cout << "空间已满！" << endl;
			return;
		}
		this->pAddress[this->m_size] = value1;
		this->m_size++;
	}

	// 尾删法
	void Pop_Back()
	{
		if (this->m_size == 0)
		{
			cout << "数据为空！" << endl;
			return;
		}
		this->m_size--;
	}

	//[]数组访问符号的重载
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//返回数组容量
	int getCapacity()
	{
		return this->capacity;
	}

	//返回数组大小
	int getSize()
	{
		return this->m_size;
	}

	//析构函数
	~myArray()
	{
		/*cout << "析构函数调用" << endl;*/
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

private:
	int capacity;
	int m_size;
	T* pAddress;
};
