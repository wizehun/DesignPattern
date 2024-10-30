#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

int main()
{
    ICalc* calc = load_proxy();

    int n1 = calc->Add(1, 2);

    delete calc;    // 이렇게 해도 될까?
}




