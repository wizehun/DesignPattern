#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;                         // �Ϲ����� �ڵ�
    std::vector<int, std::allocator<int>> v;    // ��� �� �ڵ��� (����Ʈ)

    v.resize(4);
}