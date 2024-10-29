#include <iostream>
#include <vector>

// #1. ��� �Ļ� Ŭ������ ������ Ư¡�� �ݵ��
//     ��� Ŭ�������� �־�� �Ѵ�.
//     �������� ��Ģ�� �ƴ� "������ ��Ģ"!!

//     �׷��� ��� Ŭ���� �����ͷ� �ش� ����� ����Ҽ� �ִ�.

// #2. ��� Ŭ������ ���� �Լ��߿���
//	   �Ļ� Ŭ������ override �ϴ� ���� �ݵ�� virtual �̾�� �Ѵ�.
//     (������ ��Ģ�� �ƴ� ������ ��Ģ)

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	virtual void draw() { std::cout << "draw shape\n"; }

	// �Ʒ� �Լ��� virtual �ұ�� ? non-virtual �� �ұ�� ?

	// �Ļ�Ŭ������ override ������ ����. - non-virtual
	// virtual �ص� ������ virtual �� "������."
	void set_color(int c) { color = c; }


	// ������ ���ϴ� ����� �������� �ٸ���.
	// => �Ļ�Ŭ������ override �ϰ� �ǹǷ� virtual 
	virtual int get_area() { return 0; }
};



class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect\n"; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle\n"; }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			v.push_back(new Rect);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto e : v)
			{
				e->draw(); // ������(polymorphism)
						   // => ������ ǥ������ ��Ȳ(������ü�� ����)��
						   //    ���� �ٸ��� �����ϴ°�

				// ��ü���� ����� 3�� Ư¡ : ĸ��ȭ, ���, ������

				// �������� ����
				// => �� ������ ���ο� ����(Triangle)�� �߰��Ǿ
				// => "e->draw()" �� ������ �ʽ��ϴ�.
				// => OCP ����
			}
		}
	}
}


