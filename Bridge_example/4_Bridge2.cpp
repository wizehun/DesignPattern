// Point.h
class Point
{
    int debug;  // <= ���߿� �߰�
    // ������� �����ϴ� ��� �ҽ��� �ٽ� ������ �Ǿ�� �Ѵ�.
    // 1000���� �ҽ����� #include �ߴٸ�
    // ��� �ٽ� ������!!
    // ȭ��(��)(��ȭ�� ����) �߻��ߴµ�, ��� ������ �Ű� �پ���.
    // ��ȭ���� ����.
    int x, y;
public:
    void print();
};

// Point.cpp
#include "Point.h"

void Point::print() { } // ���� ����






// main.cpp
#include "Point.h"
int main()
{
    Point p;
    p.print();
}

