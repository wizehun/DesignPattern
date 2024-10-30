#define USING_GUI
#include "cppmaster.h"

// 서버를 대신하는 대행자(proxy)를 만들어서 사용한다.
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
    // 이제 클라이언트 제작자는 서버를 대신하는 클래스인 "Calc"를 사용한다.
    Calc* calc = new Calc;

    int n1 = calc->Add(1, 2);
    int n2 = calc->Sub(1, 2);

    std::cout << n1 << ", " << n2 << std::endl;
}





