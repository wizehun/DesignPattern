// function1.cpp
#include <iostream>
#include <functional>
using namespace std::placeholders; // _1, _2, _3 ...


void foo(int a, int b, int c, int d)
{
    printf("foo : %d, %d, %d, %d\n", a, b, c, d);
}

void foo1(int a) {}
void foo2(int a, int b) {}

int main()
{
    // C����� �Լ� �����ʹ� �������� �����մϴ�.
//	void (*f1)(int) = &foo1; // ok
//	f1 = &foo2; // error. foo2 �� ���ڰ� 2��..

    // C++ std::function �� "�Լ�������" �� ��ü�ؼ� ���..
    // ���� : std::function<�Լ����> 

    std::function<void(int)> f1;

    f1 = &foo1;
    f1(10); // foo1(10)

    //	f1 = &foo2; // error. foo2�� ����2����

        // ���� : std::function �� std::bind ����� �������� �ִ�.
    f1 = std::bind(&foo2, 3, _1);

    f1(10); // foo2(3, 10);


    f1 = std::bind(&foo, 3, 5, _1, 0);

    f1(9); // foo(3, 5, 9, 0);

    // ���
    // std::function<void(int)> ��
    // ���ڰ� int �Ѱ� �̻��� �Լ���
    // std::bind() �� ����ϸ� ��� �ּҸ� ������ �ִ�.


    // std::function<void()> �� ��� ������ �Լ��� ��´�.
}
