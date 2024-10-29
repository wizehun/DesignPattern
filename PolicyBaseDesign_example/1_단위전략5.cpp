#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;                         // 일반적인 코드
    std::vector<int, std::allocator<int>> v;    // 사실 이 코드임 (디폴트)

    v.resize(4);
}