#include <vector>
#include <iostream>
#include <ranges> // C++20 ���� 30������ view�� �����ȴ�.
                  // ������ �ɼ��� C++20 ���� (������Ʈ-�Ӽ�)

int main()
{
    std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

    std::ranges::take_view tv(v, 5); // ���ۺ��� 5����
    std::ranges::filter_view fv(tv, [](int n) {return n % 2 == 0; }); // �� �� ¦���� filter
    std::ranges::reverse_view rv(fv); // �װ� reverse

    // �����͸� ������ ���� �ƴ϶� view�� ������ �� (���Ŀ� ������ �����ϸ�, �����Ѱ� ���δ�.)
    
    // �Ʒ� �ڵ�� ���ڵ�� ������ �����մϴ�. ( operator | ������ ������ ��ũ��)
    // ������ ������ ���� ó�� ����Ҽ� �ְ� �����ϴ� ��
    auto rv = v | std::views::take(5)
        | std::views::filter([](int n) { return n % 2 == 0; })
        | std::views::reverse;

    for (auto e : rv)
    {
        std::cout << e << ", ";
    }
    std::cout << "\n";
}
