#define USING_GUI
#include "cppmaster.h"

// Ŭ���̾�Ʈ �����ڴ� ���������ڿ��� 2���� ������ �޾ƾ� �Ѵ�.

// ICalc.h          : �������̽��� �ִ� ���
// CalcProxy.dll    : Proxy �� ��� ���� ��� (Ŭ������ �̸� ������ �� ��)

#include "ICalc.h"

int main()
{
    ICalc* calc = load_proxy();

    int n1 = calc->Add(1, 2);
    int n2 = calc->Sub(1, 2);

    std::cout << n1 << std::endl;
    std::cout << n2 << std::endl;
}




