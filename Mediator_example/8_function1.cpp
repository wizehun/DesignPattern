// function1.cpp
#include <iostream>
#include <functional>

// 4항함수 : 인자가 4개인 함수
void foo(int a, int b, int c, int d)
{
    printf("foo : %d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
    foo(1, 2, 3, 4);

    // std::bind() 사용법 : std::bind(N항함수의 주소, N개의 인자)

    auto f1 = std::bind(&foo, 1, 2, 3, 4); // foo의 인자4개를
                                           // 1, 2, 3,4, 로 고정한 새로운 함수 f1
    f1();   // 4항함수 => 0항함수로 변경

    auto f2 = std::bind(&foo, 3, 8, _1, _2);    // 4항 => 2항
    f2(4, 7);   // foo(3, 8, 4, 7);

    auto f3 = std::bind(&foo, _2, 3, _3, _1);   // 4항 => 3항, 인자의 순서 지정 가능
    f3(8, 2, 6); // foo(2, 3, 6, 8)
}

