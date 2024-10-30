#define USING_GUI
#include "cppmaster.h"

// Proxy 제작자 : 서버 제작자
// Proxy 사용자 : 클라이언트 제작자

struct ICalc
{
    virtual int Add(int a, int b) = 0;
    virtual int Sub(int a, int b) = 0;
    virtual ~ICalc() {}
};

class Calc
{
    int server;
public:
    Calc() { server = ec_find_server("Calc"); }
    int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
    int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

int main()
{
    Calc* calc = new Calc;  // 이렇게 사용하면 "강한 결합"이 된다.
                            // 나중에 새로운 Proxy가 배포되면 코드가 수정되어야 함.
                            // 결국 약한 결합 (인터페이스)로 사용해야한다.

    int n1 = calc->Add(1, 2);
    int n2 = calc->Sub(1, 2);

    std::cout << n1 << ", " << n2 << std::endl;
}





