#include <iostream>
using namespace std;
#include <cstring>

class Girl {
public:
    string name;
    int age;
    static char *m_pool; // �ڴ�ص���ʼ��ַ��һ����û�����͵ģ�Ϊ�˷�����㣬����ʹ��char*��Ϊָ������

    static bool initpool() {
        m_pool = (char *)malloc(90);
        if(m_pool == nullptr) return false;
        memset(m_pool, 0, 90);
        cout << "�ڴ�ص���ʼ��ַΪ��" << (void *)m_pool << endl;
        return true;
    }
    static void freepool() {
        if(m_pool == 0) return;
        free(m_pool);
        m_pool = nullptr;
        cout << "�ڴ���Ѿ��ͷš�" << endl;
    }
    Girl(string name, int age) {
        this->name = name;
        this->age = age;
        cout << "Girl�Ĺ��캯����" << endl;
    }
    ~Girl() {
        cout << "Girl������������" << endl;
    }
    void *operator new(size_t size) {
        if(m_pool[0] == 0) 
        {
            cout << "�����˵�һ���ڴ棺" << (void *)(m_pool + 1) << endl;
            m_pool[0] = 1;
            return m_pool + 1;
        }
        if(m_pool[29] == 0)
        {
            cout << "�����˵ڶ����ڴ棺" << (void *)(m_pool + 29) << endl;
            m_pool[29] = 1;
            return m_pool + 29;
        }
        cout << "��Ա����new�����أ�" << size << "�ֽڡ�" << endl;
        void *ptr = malloc(size);
        //cout << "���뵽���ڴ��ַΪ��" << ptr << endl;
        return ptr;
    }
    void operator delete(void *ptr) {
        if(ptr == 0) return;
        if(ptr == m_pool + 1)
        {
            cout << "�ͷ��˵�һ���ڴ棺" << (void *)(m_pool + 1) << endl;
            m_pool[0] = 0;
            return;
        }
        if(ptr == m_pool + 29)
        {
            cout << "�ͷ��˵ڶ����ڴ棺" << (void *)(m_pool + 29) << endl;
            m_pool[29] = 0;
            return;
        }
        cout << "��Ա����delete�����ء�\n";
        free(ptr);
    }
};

char *Girl::m_pool = 0;//��̬��Ա���������������ʼ��,��ʼ���ڴ��ָ��
//�ڴ�أ������ڴ��ָ������飬Ϊ�˷����Ч�����ڴ�
int main() {
    if(Girl::initpool()==false) {
        cout << "��ʼ���ڴ��ʧ�ܡ�" << endl;
        return 0;
    }
    Girl *p1 = new Girl("С��", 18);
    cout << "p1�ĵ�ַΪ��" << p1 << "  ������" << p1->name << "  ���䣺" << p1->age << endl;
    Girl *p2 = new Girl("С��", 19);
    cout << "p2�ĵ�ַΪ��" << p2 << "  ������" << p2->name << "  ���䣺" << p2->age << endl;
    delete p1;
    delete p2;

    Girl::freepool();
    system("pause");
    return 0;
}