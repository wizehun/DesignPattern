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

// DLL 안에 있는 Proxy 클래스 이름은
// 클라이언트 개발자가 알 수 없고, 알 필요도 없고, 사용해도 안된다. (강한 결합이 되기 때문에)
// => DLL 내부에 약속된 함수를 만들고, 그 안에서 객체를 생성해야 한다.

extern "C" __declspec(dllexport)    // DLL 안에 함수를 만들 때 필요
ICalc* create()
{
    return new Calc;
}

// 새로운 Proxy DLL을 만들 때도 규칙("create" 함수가 있어야 한다는)을 지켜야 한다.
