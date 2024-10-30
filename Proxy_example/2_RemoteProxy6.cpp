#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

int main()
{
    ICalc* calc1 = load_proxy();

    calc1->AddRef();    // 규칙 1. Proxy를 생성한 후에는 참조계수 증가

    ICalc* calc2 = calc1;
    calc2->AddRef();    // 규칙 2. Proxy 포인터 복사하면 참조계수 증가

    calc1->Release();   // 규칙 3. 더이상 포인터를 사용하지 않으면 참조계수 감소

    std::cout << "-------------\n";

    calc2->Release();   // 이 순간 Proxy가 delete (RefCount 가 0이 됨)
    
    std::cout << "-------------\n";
}




