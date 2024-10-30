// 7_싱글톤1 - 123 page
#include <iostream>

class Cursor
{
    // 규칙 1. 생성자를 private 에 놓는다.
private:
    Cursor() {}

    // 규칙 2. 컴파일러가 복사생성자와 대입연산자를 만들지 못하게 한다.
    Cursor(const Cursor&) = delete;             // 함수 삭제 문법 - 복사 생성자를 만들지 말라
    Cursor& operator=(const Cursor&) = delete;  // 관례상 복사를 금지하면, 대입도 금지

    // 규칙 3. 오직 1개의 객체만 만들어서 반환하는 static 멤버 함수
public:
    static Cursor& get_instance()
    {
        static Cursor instance; // 핵심 : static 지역 변수
        return instance;
    }
};

int main()
{
    // Cursor c1, c2; // Error. (private 생성자)

    Cursor& c1 = Cursor::get_instance();
    Cursor& c2 = Cursor::get_instance();

    std::cout << &c1 << std::endl;
    std::cout << &c2 << std::endl;
}








