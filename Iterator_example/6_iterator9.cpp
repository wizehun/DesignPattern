#include <vector>
#include <iostream>
#include <ranges> // C++20 부터 30여개의 view가 제공된다.
                  // 컴파일 옵션을 C++20 으로 (프로젝트-속성)

int main()
{
    std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

    std::ranges::take_view tv(v, 5); // 시작부터 5개만
    std::ranges::filter_view fv(tv, [](int n) {return n % 2 == 0; }); // 그 중 짝수만 filter
    std::ranges::reverse_view rv(fv); // 그걸 reverse

    // 데이터를 변경한 것이 아니라 view만 설정한 것 (이후에 데이터 변경하면, 변경한게 보인다.)
    
    // 아래 코드는 위코드와 완전히 동일합니다. ( operator | 연산자 재정의 테크닉)
    // 리눅스 파이프 라인 처럼 사용할수 있게 지원하는 것
    auto rv = v | std::views::take(5)
        | std::views::filter([](int n) { return n % 2 == 0; })
        | std::views::reverse;

    for (auto e : rv)
    {
        std::cout << e << ", ";
    }
    std::cout << "\n";
}
