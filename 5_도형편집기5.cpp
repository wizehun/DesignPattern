#include <iostream>
#include <vector>

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	virtual void draw() { std::cout << "draw shape\n"; }

	void set_color(int c) { color = c; }

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
				e->draw(); 
			}
		}

		else if (cmd == 8)
		{
			std::cout << "���° ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;

			// k��° ������ ���纻�� �����ؼ� v�� �߰��մϴ�.
			// ��� �ؾ� �ұ�� ? k��° ������ � Ÿ���ϱ�� ?

			// ��� #1. dynamic_cast�� ��������.
			if (dynamic_cast<Rect*>(v[k]) != nullptr)
			{
				// �簢���̶�� �����ؼ� ���纻����
			}
			else if (dynamic_cast<Circle*>(v[k]) != nullptr)
			{
				// ���̶�� �����ؼ� ���纻����
			}

			// �� �ڵ�� OCP �����Ҽ� ����.
			// => Triangle �߰��� �ڵ尡 �߰��Ǿ�� �Ѵ�.
			// => ��κ��� ��� dynamic_cast �� ���� ���� �������� �ȴ�.
		}
	}
}


