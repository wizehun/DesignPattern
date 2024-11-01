class Dialog
{
public:
    void close(int code) {}

    static void close2(int code) {}
};

void foo(int a) {}

int main()
{
    void(*f1)(int) = &foo;			 // ok 	
    void(*f2)(int) = &Dialog::close; // error. ��� �Լ��̹Ƿ� this �߰��� �Լ�

    void(*f3)(int) = &Dialog::close2; // ok. static ��� �Լ��� this�� �߰��ȵ�.

    // 1. �Ϲ��Լ� �����Ϳ� ��� �Լ��� �ּҸ� ������ �����ϴ�.
    // 2. �Ϲ��Լ� �����Ϳ� static ��� �Լ��� �ּҸ� ������ �ֽ��ϴ�.

    // ����) ����Լ� �ּҴ� "��� �Լ�������" ��� ������ �ֽ��ϴ�.
    void(Dialog:: * f4)(int) = &Dialog::close; // ok
}