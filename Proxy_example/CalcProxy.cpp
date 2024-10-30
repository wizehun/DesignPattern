// CalcProxy.cpp
#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"
#include <atomic>  // ��Ƽ������ ������ Ÿ���� ����Ҷ�!!

class Calc : public ICalc
{
    int server;
    // int ref = 0;             // ��Ƽ������ȯ�濡�� �����ϰ� +, - ���� ����
    std::atomic<int> ref = 0;   // ��Ƽ������ ����

public:
    void AddRef() { ++ref; }
    void Release() { if (--ref == 0) delete this; }

    ~Calc() { std::cout << "~Calc\n"; }

    Calc() { server = ec_find_server("Calc"); }

    int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
    int Sub(int a, int b) { return ec_send_server(server, 2, a, b); ; }
};

extern "C" __declspec(dllexport)
ICalc* create()
{
    return new Calc;
}