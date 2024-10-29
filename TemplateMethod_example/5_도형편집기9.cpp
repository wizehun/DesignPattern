#include <iostream>
#include <vector>


// ���� ����
// => �ڵ� ���� & �����غ� ����


class unsupported_operation {};

class Shape
{
	int color = 0;

protected:
	Shape() {}

public:
	virtual ~Shape() {}

	void draw()
	{
		std::cout << "lock mutex\n";
		draw_imp();
		std::cout << "unlock mutex\n";

	}
	void set_color(int c) { color = c; }

protected:
	virtual void draw_imp() = 0;


public:
	virtual Shape* clone() { throw unsupported_operation(); }

	virtual int get_area() { return -1; }

};




class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw rect\n"; }

	Shape* clone()  override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw_imp() override  { std::cout << "draw circle\n"; }

	Shape* clone() override  { return new Circle(*this); }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		// ������ �� ���� #1. ��ü�� ������ OCP�� �����ϰ� �Ҽ� ������ ?
		// => Triangle �� �߰��Ǿ �Ʒ� �ڵ尡 ������� �ʰ�!!
		// => ���丮 ������ ����ϸ� �˴ϴ�. (����ϳ� ����� �˴ϴ�.)

		// ������ �� ���� #2. Undo/Redo ����� �߰��Ϸ��� ��� �ؾ� �ұ� ?
		// => Command ������ ���� �˴ϴ�.
		// => Undo/Redo �Ҷ� ����ϴ� ����!!
		// => ����ϳ� ����� �˴ϴ�.

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
				e->draw(); // ������, OCP ����
			}
		}
		else if (cmd == 8)
		{
			std::cout << "���° ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->clone()); // ������, OCP ����

		}
	}
}


