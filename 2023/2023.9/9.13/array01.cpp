#include <iostream>
using namespace std;

template<typename T>
class MyArray {
public:
	// �вι���
	MyArray(int capacity)
	{
		this->_arrCapacity = capacity;
		this->_arrSize = 0;
		this->_addrHead = new T[this->_arrCapacity];
	}
	// ���ù���
	MyArray(const MyArray<T>& arr)
	{
		if (arr._arrSize != 0)
		{
			delete[] arr._addrHead;
			arr._addrHead = nullptr;
		}
		this->_arrCapacity = arr._arrCapacity;
		this->_addrHead = new T[this->_arrCapacity];
		this->_arrSize = arr._arrSize;
		for (int i = 0; i < arr._arrSize; i++)
		{
			this->_addrHead[i] = arr._addrHead[i];
		}
	}
	// �����±�
	T& operator[](int index)
	{
		return this->_addrHead[index];
	}
	// ���صȺ�
	MyArray<T>& operator=(const MyArray<T>& arr)
	{
		if (arr._arrSize != 0)
		{
			delete[] arr._addrHead;
			arr._addrHead = nullptr;
		}
		this->_arrCapacity = arr._arrCapacity;
		this->_addrHead = new T[this->_arrCapacity];
		this->_arrSize = arr._arrSize;
		for (int i = 0; i < arr._arrSize; i++)
		{
			this->_addrHead[i] = arr._addrHead[i];
		}
		return *this;
	}
	// β����ֵ
	void PushBack(T& data)
	{
		if (this->_arrSize >= this->_arrCapacity)
		{
			return;
		}
		this->_addrHead[this->_arrSize] = data;
		this->_arrSize++;
	}
	// β����ֵ
	void PushBack(T&& data)
	{
		if (this->_arrSize >= this->_arrCapacity)
		{
			return;
		}
		this->_addrHead[this->_arrSize] = data;
		this->_arrSize++;
	}
	// βɾ
	void PopBack()
	{
		if (this->_arrSize == 0)
		{
			return;
		}
		this->_arrSize--;
	}
	// ����size
	int size()
	{
		return this->_arrSize;
	}
	// ����
	~MyArray()
	{
		delete[] this->_addrHead;
		this->_addrHead = nullptr;
	}

public:
	int _arrCapacity;//����
	int _arrSize;//��ǰԪ�ظ���
	T* _addrHead;//�����׵�ַ
};
int main()
{
	MyArray<int> arr(10);
	int a = 1, b = 2, c = 3;
	arr.PushBack(a);
	arr.PushBack(b);
	arr.PushBack(c);
	arr.PushBack(4);
	arr.PushBack(5);
	arr.PopBack();
	for (int i = 0; i < arr._arrSize; i++)
	{
		cout << "  i = " << arr[i];
	}
	cout << endl;
	system("pause");
	return 0;
}