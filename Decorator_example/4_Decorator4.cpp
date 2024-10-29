// Decorator - 65 page
#include <iostream>



// Ŭ������ 
// Ŭ������ "����� �߰��ϴ� Ŭ����(Decorator)"
// �� ������ ��� Ŭ������ �־��
// "��ø�� ����߰�" �� �����ϴ�.

struct IDraw
{
	virtual void draw() = 0;
	virtual ~IDraw() {}
};





// "��ƼĿ ����" Ŭ������� ������ ������. 
class PhotoSticker : public IDraw
{
public:
	void take() { std::cout << "take Photo\n"; }
	void draw() { std::cout << "draw Photo\n"; }
};


class Emoticon : public IDraw
{
	IDraw* origin;	// �ٽ�!!
public:
	Emoticon(IDraw* ps) : origin(ps) {}

	void draw()
	{
		std::cout << "@@@@@@@@@@@@@@\n";
		origin->draw();

		std::cout << "@@@@@@@@@@@@@@\n";
	}
};

class Frame : public IDraw
{
	IDraw* origin;
public:
	Frame(IDraw* ps) : origin(ps) {}

	void draw()
	{
		std::cout << "##############\n";
		origin->draw();

		std::cout << "##############\n";
	}
};

int main()
{
	PhotoSticker ps;
	ps.take();

	ps.draw();

	Emoticon e(&ps);
	e.draw();

	Frame f(&e);
	f.draw();	// ��� �߰��Ȱ��� ���

	ps.draw();	// ��� �߰����� ��ü�� ��밡��. 
}
/*
// ���� ������ ����
// => �Ʒ�ó�� "filter" �������� �ϸ� �ȵǳ��� ?
PhotoSticker ps;
ps.take();

ps.add_filter(new Emoticon);
ps.add_filter(new Frame);

ps.draw();  // ��ϵ� ���͸� ��� ����ϰ�
			// �Կ��� ���� ���
			 // emoticon.draw()
			 // frame.draw()
			 // ps.draw()
// �� ���� "���� �׸��� ���" �ϴ� ����� �����ϴ�.
// => ���͸� �����Ŀ� �׷��� �մϴ�.

// decorator �� ��� �߰��Ŀ��� "���� ����"�� ����ϴ� ��
*/