#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
    
    for (auto e : v)
    {
        std::cout << e << ", ";
    }
    std::cout << "\n";

    // 위 for문의 원리
    // 위 코드를 컴파일러는 아래 처럼 변경
    //-----------------------------------------------
    auto first = v.begin();
    auto last = v.end();
    for (; first != last; ++first)
    {
        auto e = *first;
    //-----------------------------------------------
        std::cout << e << ", ";
    }
}