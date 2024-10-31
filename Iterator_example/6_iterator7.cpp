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

    // �� for���� ����
    // �� �ڵ带 �����Ϸ��� �Ʒ� ó�� ����
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