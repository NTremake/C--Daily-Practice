#pragma once
#include <iostream>
using namespace std;
#include <string>

template<class T>
class myArray
{
public:
	//���캯��
	myArray(int capacity)
	{
		/*cout << "���캯������" << endl;*/
		this->capacity = capacity;
		this->m_size = 0;
		this->pAddress = new T[this->capacity];
	}

	//��������
	myArray(const myArray& arr)
	{
		/*cout << "�������캯������" << endl;*/
		this->capacity = arr.capacity;
		this->m_size = arr.m_size;
		this->pAddress = new T[arr.capacity * sizeof(T)];
		for (int i = 0; i < this->m_size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//�Ⱥŵ�����
	myArray& operator=(const myArray& arr)
	{
	//cout << "operator=��������" << endl;
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

	//β�巨
	void Push_Back(const T& value1)
	{
		if (this->capacity == this->m_size)
		{
			cout << "�ռ�������" << endl;
			return;
		}
		this->pAddress[this->m_size] = value1;
		this->m_size++;
	}

	// βɾ��
	void Pop_Back()
	{
		if (this->m_size == 0)
		{
			cout << "����Ϊ�գ�" << endl;
			return;
		}
		this->m_size--;
	}

	//[]������ʷ��ŵ�����
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//������������
	int getCapacity()
	{
		return this->capacity;
	}

	//���������С
	int getSize()
	{
		return this->m_size;
	}

	//��������
	~myArray()
	{
		/*cout << "������������" << endl;*/
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
