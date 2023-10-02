#include <iostream>
#include <cstring>
using namespace std;

class BaseException : public exception
{
public:
    virtual void what() = 0;
    virtual ~BaseException(){};
};

class TatgetNullEX :public BaseException {
public:
    void what() {
        cout << "Ŀ������Ϊ�գ�" << endl;
    }
};
class SourceNullEX :public BaseException {
public:
    void what() {
        cout << "��Դ����Ϊ�գ�" << endl;
    }
};
void CopyChar(char* target, char* source) {
    if(target == nullptr) {
        throw TatgetNullEX();
    }
    if(source == nullptr) {
        throw SourceNullEX();
    }
    while(*source != '\0') {
        *target = *source;
        target++;
        source++;
    }
}
int main() {
    char str[] = "abcd";
    char buf[1024] = {0};
    try {
        CopyChar(buf, str);
    }
    catch(BaseException& ex) {
        ex.what();
    }
    cout << buf << endl;
    system("pause");
    return 0;
}