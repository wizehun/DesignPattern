// Decorator - 65 page
#include <iostream>

// "��ƼĿ ����" Ŭ������� ������ ������. 
class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n"; }
	void draw() { std::cout << "draw Photo\n"; }
};

// ��� : ��ü�� �ƴ� Ŭ������ ����� �߰� �Ѱ�
//	      ����ð�(����)���� �߰��Ѱ��� �ƴ� �ҽ� �ۼ�(����)�ÿ� �߰��Ȱ�

class Emoticon 
{
	PhotoSticker* origin; // �ٽ� : ������ �Ǵ� ���� ���(��Ÿ�� �ƴ�)
						  // �ǹ� : �̹� �����Ǿ� �ִ� ��ü�� ����Ű�ڴٴ� ��
public:
	Emoticon(PhotoSticker* ps) : origin(ps) {}

	void draw()
	{
		std::cout << "@@@@@@@@@@@@@@\n"; 	
		origin->draw();

		std::cout << "@@@@@@@@@@@@@@\n"; 
	}
};




int main()
{
	PhotoSticker ps;
	ps.take();	
	ps.draw();	

	Emoticon e(&ps); // ps ��� �̹� ������ ��ü�� 
					 // ����� �߰��ϴ� e ��ü

	e.draw();	// e�� �߰��� ����� ����ϰ�
				// �ٽ� ps �� ����� ���
}
