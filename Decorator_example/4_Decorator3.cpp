// Decorator - 65 page
#include <iostream>

// "��ƼĿ ����" Ŭ������� ������ ������. 
class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n"; }
	void draw() { std::cout << "draw Photo\n"; }
};


class Emoticon
{
	PhotoSticker* origin; 
public:
	Emoticon(PhotoSticker* ps) : origin(ps) {}

	void draw()
	{
		std::cout << "@@@@@@@@@@@@@@\n";
		origin->draw();

		std::cout << "@@@@@@@@@@@@@@\n";
	}
};

// ���� �׸� ����� �߰��ϴ� Ŭ����
class Frame
{
	PhotoSticker* origin;
public:
	Frame(PhotoSticker* ps) : origin(ps) {}

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

//	Frame f(&ps);
	Frame f(&e); // ����� ��ø
				 // ���� �ڵ�� ����!!!
				 // �ذ��� "�����ҽ�����"
				 
	f.draw();
}
