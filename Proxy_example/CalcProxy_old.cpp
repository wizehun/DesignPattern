#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

class Calc : public ICalc
{
    int server;
public:
    Calc() { server = ec_find_server("Calc"); }

    int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
    int Sub(int a, int b) { return ec_send_server(server, 2, a, b); ; }
};

// DLL �ȿ� �ִ� Proxy Ŭ���� �̸���
// Ŭ���̾�Ʈ �����ڰ� �� �� ����, �� �ʿ䵵 ����, ����ص� �ȵȴ�. (���� ������ �Ǳ� ������)
// => DLL ���ο� ��ӵ� �Լ��� �����, �� �ȿ��� ��ü�� �����ؾ� �Ѵ�.

extern "C" __declspec(dllexport)    // DLL �ȿ� �Լ��� ���� �� �ʿ�
ICalc* create()
{
    return new Calc;
}

// ���ο� Proxy DLL�� ���� ���� ��Ģ("create" �Լ��� �־�� �Ѵٴ�)�� ���Ѿ� �Ѵ�.
