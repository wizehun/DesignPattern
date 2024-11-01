#include <iostream>

// �ٽ� 
// => �������� 3�� ���..
// => ��� ���� �Լ��� "3����" �־�� �Ѵ�.
// => "run", "attack", �� ��� �Լ��� 3���� ������..

struct IState
{
    virtual void run() = 0;
    virtual void attack() = 0;
    virtual ~IState() {}

    // slide(), jump(), fly() ���� ��� �����Լ��� ����
};

// �� ������ ���� ������ ���� ���� �մϴ�.
class NoItem : public IState
{
public:
    void run() { std::cout << "run" << std::endl; }
    void attack() { std::cout << "attack" << std::endl; }
};

class SuperItem : public IState
{
public:
    void run() { std::cout << "fast run" << std::endl; }
    void attack() { std::cout << "power attack" << std::endl; }
};

class RedItem : public IState
{
public:
    void run() { std::cout << "slow run" << std::endl; }
    void attack() { std::cout << "weak attack" << std::endl; }
};

class Character
{
    // �ᱹ �� ��� �Լ��� 3������ ����� �а�
    NoItem state1;
    SuperItem state2;
    RedItem state3;

    IState* state = &state1;

    int gold;
    int item;

public:
    void run() { state->run(); }
    void attack() { state->attack(); }

    void acquire_super_item()
    {
        state = &state2;

        // Ÿ�̸� ��ġ�� 3�еڿ� ȣ��Ǵ� �Լ�����
        // state = &state1;
    }
};
int main()
{
    Character* p = new Character;
    p->run();
    p->attack();

    p->acquire_super_item();	// �ǹ�
                                    // 1. p�� ����(��� ����Ÿ)�� ��� ���� ������
                                    // 2. �� ���� ��� ��� �Լ��� ��ü �˴ϴ�.
                                    // ��ġ �ٸ� Ŭ���� ó�� ���̰� �˴ϴ�.
                                    // "state ����" �Դϴ�.	
    
    p->run();
    p->attack();

}
// ���Ǳ⸦ ������ ���ô�.
// => ���� �־������� ���� �������� ��� ������ �ٸ��ϴ�.

// => ������ 2���� �غ��մϴ�.

// => "���� �Է�" �Ǹ� "������ ��ü �ϰ�"
// => "���Ḧ ��������" �ٽ� "������ ��ü"

// => ������ ���Ǳ��� ����Ÿ�� �������..!!


// �Ʒ� 3�� ������ "class diagram"�� �����ϴ�.
// => ��� ���ϴ� ���� �ٸ� Ŭ������ �и��� ��.
// => ��, � �ǵ��� �и��ϴ���

// 1. strategy (���� ����) : ��ü�� ����ϴ� �˰����� ��ü. �ܺο��� �����ϴ� ��찡 ����.
//                           edit.set_validator(&v1);
//                           edit.set_validator(&v2);

// 2. state (���� ����) : ��ü�� ��κ��� ��� ������ ��ü. ��ü�� ���¿� ���� ���������� ��ü
//                          ���Ǳ�.insert_coin(100);
//                               => �� ���� ��� ���� ��ü
//                          ĳ����.acquire_item();
//                          => ��� ������ ��κ� ���ο��� ����

// 3. builder : ������ ��ü�� ����µ�, ������ �������� �����.
//              �� ������ �ܰ�� ����� �� �ִ�.



