// 15page ~ 
#include <iostream>
#include <vector>

class Shape
{
	int color;
public:
	virtual ~Shape() {}
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
//			Rect rc;	// �̷��� ����� {} ����� ��� �ı� �˴ϴ�.
			Rect* p = new Rect; // ��� ����Ϸ��� �̷��� �ؾ� �մϴ�.
			v.push_back(p);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle); 
		}
		else if (cmd == 9)
		{
			for (auto e : v)
				e->draw();	// A. error.
		}
	}
}

// �� A �κ��� �����ϱ�� ?
// => ���� ��ü�� Rect, Circle ������
// => v ���� Shape* Ÿ������ ����
// => Shape ���� draw �� ����. �׷��� ����
// 
// �ذ�å�� ����� ?
// => �����ҽ�����
