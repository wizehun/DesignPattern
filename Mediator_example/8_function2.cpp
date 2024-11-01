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
    // C언어의 함수 포인터는 유연성이 부족합니다.
//	void (*f1)(int) = &foo1; // ok
//	f1 = &foo2; // error. foo2 는 인자가 2개..

    // C++ std::function 은 "함수포인터" 를 대체해서 사용..
    // 사용법 : std::function<함수모양> 

    std::function<void(int)> f1;

    f1 = &foo1;
    f1(10); // foo1(10)

    //	f1 = &foo2; // error. foo2는 인자2개라서

        // 장점 : std::function 은 std::bind 결과를 담을수도 있다.
    f1 = std::bind(&foo2, 3, _1);

    f1(10); // foo2(3, 10);


    f1 = std::bind(&foo, 3, 5, _1, 0);

    f1(9); // foo(3, 5, 9, 0);

    // 결론
    // std::function<void(int)> 는
    // 인자가 int 한개 이상인 함수라도
    // std::bind() 를 사용하면 모두 주소를 담을수 있다.


    // std::function<void()> 는 모든 종류의 함수를 담는다.
}
