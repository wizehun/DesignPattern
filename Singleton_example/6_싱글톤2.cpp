#include <iostream>

// static ��� ����Ÿ vs static ��������

// static �������� : �Լ��� ���� ȣ��Ǵ� ���� Cursor() ������ ȣ��
//					�Լ��� ȣ������ ������ Cursor() ������ ȣ�� �ȵ�
//					������ �ʱ�ȭ

// static ��� ����Ÿ : main �Լ� �� ����Ǳ� ���� Cursor ������ ȣ��
//						�ѹ��� ������� �ʾƵ� Cursor ������ ȣ��
//						�̸� �ʱ�ȭ.



class Cursor
{
private:
    Cursor() { std::cout << "Cursor()\n"; }
    Cursor(const Cursor&) = delete;
    Cursor& operator=(const Cursor&) = delete;

    //	Cursor instance;		// error
    static Cursor instance; // ok. static ��� ����Ÿ�� �ڽ� Ÿ�԰���
public:
    static Cursor& get_instance()
    {
        //		static Cursor instance; 
        return instance;
    }
};
Cursor Cursor::instance; // static ��� ����Ÿ�� �ܺ� ���� �ʿ�

int main()
{
    std::cout << "=======\n";
    //	Cursor& c1 = Cursor::get_instance();

}


