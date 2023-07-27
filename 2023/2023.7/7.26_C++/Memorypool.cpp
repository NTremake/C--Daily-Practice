#include <iostream>
using namespace std;
#include <cstring>

class Girl {
public:
    string name;
    int age;
    static char *m_pool; // 内存池的起始地址，一般是没有类型的，为了方便计算，这里使用char*作为指针类型

    static bool initpool() {
        m_pool = (char *)malloc(90);
        if(m_pool == nullptr) return false;
        memset(m_pool, 0, 90);
        cout << "内存池的起始地址为：" << (void *)m_pool << endl;
        return true;
    }
    static void freepool() {
        if(m_pool == 0) return;
        free(m_pool);
        m_pool = nullptr;
        cout << "内存池已经释放。" << endl;
    }
    Girl(string name, int age) {
        this->name = name;
        this->age = age;
        cout << "Girl的构造函数。" << endl;
    }
    ~Girl() {
        cout << "Girl的析构函数。" << endl;
    }
    void *operator new(size_t size) {
        if(m_pool[0] == 0) 
        {
            cout << "分配了第一块内存：" << (void *)(m_pool + 1) << endl;
            m_pool[0] = 1;
            return m_pool + 1;
        }
        if(m_pool[29] == 0)
        {
            cout << "分配了第二块内存：" << (void *)(m_pool + 29) << endl;
            m_pool[29] = 1;
            return m_pool + 29;
        }
        cout << "成员函数new的重载：" << size << "字节。" << endl;
        void *ptr = malloc(size);
        //cout << "申请到的内存地址为：" << ptr << endl;
        return ptr;
    }
    void operator delete(void *ptr) {
        if(ptr == 0) return;
        if(ptr == m_pool + 1)
        {
            cout << "释放了第一块内存：" << (void *)(m_pool + 1) << endl;
            m_pool[0] = 0;
            return;
        }
        if(ptr == m_pool + 29)
        {
            cout << "释放了第二块内存：" << (void *)(m_pool + 29) << endl;
            m_pool[29] = 0;
            return;
        }
        cout << "成员函数delete的重载。\n";
        free(ptr);
    }
};

char *Girl::m_pool = 0;//静态成员变量必须在类外初始化,初始化内存池指针
//内存池，类似于存放指针的数组，为了方便高效管理内存
int main() {
    if(Girl::initpool()==false) {
        cout << "初始化内存池失败。" << endl;
        return 0;
    }
    Girl *p1 = new Girl("小红", 18);
    cout << "p1的地址为：" << p1 << "  姓名：" << p1->name << "  年龄：" << p1->age << endl;
    Girl *p2 = new Girl("小王", 19);
    cout << "p2的地址为：" << p2 << "  姓名：" << p2->name << "  年龄：" << p2->age << endl;
    delete p1;
    delete p2;

    Girl::freepool();
    system("pause");
    return 0;
}