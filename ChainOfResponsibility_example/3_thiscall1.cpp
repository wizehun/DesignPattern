#include <iostream>

// �ٽ� 
// 1. ��� �Լ��� ���ڷ� "this" �� �߰��˴ϴ�. - this call �̶�� �մϴ�
// 2. static ��� �Լ��� "this" �� �߰����� �ʽ��ϴ�.

class Point
{
    int x = 0;
    int y = 0;
public:
    void set(int a, int b)	// void set( Point* this, int a, int b)
    {						// {
        x = 0;				//		this->x = 0;
        y = 0;				//		this->y = 0; ���� ����˴ϴ�.

        std::cout << this << std::endl;
    }

    static void foo(int a)	// void foo(int a)
    {						// {
        x = a;				//		this->x = a; �Ǿ� �ϴµ�, 
                            //	    this �� �����Ƿ� ����. 
    }
};
int main()
{
    Point::foo(10);	// call Point::foo(10)

    Point p1;
    Point p2;

    p1.set(10, 20); // call Point::set(&p1, 10, 20)
    // ó�� ����˴ϴ�.
}