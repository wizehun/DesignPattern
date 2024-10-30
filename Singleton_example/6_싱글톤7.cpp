#include <iostream>


class Cursor
{
private:
    Cursor() {}

    Cursor(const Cursor&) = delete;
    Cursor& operator=(const Cursor&) = delete;

public:

    // C++11(java, C# �� ��������) ���� static ���������� ������ ȣ����
    // ��Ƽ�����忡 �����մϴ�.
    // �Ʒ��ڵ忡�� "������ A" �� ���� �����ؼ� �����ڸ� ȣ���ϰ� ������
    // "������ B" �� �����ϸ� A�� ������ ȣ���� ����ɶ����� ��� �մϴ�.
    // => ��, ����ȭ ��.
    // => ����ȭ ����� "spin lock(busy waiting)" �Դϴ�.
    static Cursor& get_instance()
    {
        static Cursor instance; // lock()
                                // Cursor() ȣ��
                                // unlock()

        return instance;
    }

};
int main()
{



}


