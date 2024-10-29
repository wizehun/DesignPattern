#include <iostream>
#include <vector>

// #1. template method ����
// => ������ ���� ��ü���� �帧�ӿ� ��� ���ؾ� �ϴ� ���� ã�Ƽ�
//    ������ �����Լ��� �и��ϴ� ����

// => �Ļ�Ŭ��������
// => ������ ��Ģ�� ���� ������
// => ���ؾ� �ϴ� �͸� �����Ҽ� �ְ� �ϴ� ������ ����





class Shape
{
	int color;
public:
	virtual ~Shape() {}

	// �ٽ� : ���뼺�� �������� �и�
	// => ������ ���� �ڵ� �帧 �ӿ� �ִ�
	// => ���ؾ� �ϴ� �ڵ�� �и��Ǿ�� �Ѵ�.
	// => ���ϴ� ���� ������ �����Լ��� �и��Ѵ�.

protected:
	virtual void draw_imp()
	{
		std::cout << "draw shape\n";
	}
	// �Ʒ� �Լ��� ������ ���� ������ ��Ģ�̹Ƿ� override ���� �ʰԵȴ�
	// non-virtual 
public:
	void draw() 
	{ 
		std::cout << "lock mutex\n";
		draw_imp();
		std::cout << "unlock mutex\n";

	}







	void set_color(int c) { color = c; }

	virtual int get_area() { return 0; }


	virtual Shape* clone()
	{
		Shape* p = new Shape;   
		p->color = this->color; 
		return p;
	}
};

class Rect : public Shape
{
public:
	void draw_imp() { std::cout << "draw rect\n"; }

	virtual Shape* clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw_imp() { std::cout << "draw circle\n"; }

	virtual Shape* clone() { return new Circle(*this); }
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
				e->draw();
			}
		}

		else if (cmd == 8)
		{
			std::cout << "���° ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;


			v.push_back(v[k]->clone()); 

		}
	}
}


