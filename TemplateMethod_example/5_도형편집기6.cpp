#include <iostream>
#include <vector>

// #1. ������ �����̶� ?
// => 1994�� �߰��� å�� ����
// => 4���� ���ڰ� "��ÿ� �����ϴ� �ڵ� ��Ÿ��" �� "�̸��� �ο�" �Ѱ�
// => �� 23���� �̸�. 
// => GoF's �� ������ �����̶�� �մϴ�.
// => "Gangs Of Four" : 4���� ����

// #2. prototype ���� : ��ü�� ���纻�� ����� ����
//						clone() �����Լ��� ����� ���
//						����� �� ������ "����ϳ�"


// #3. �����丵���� ���Ǵ� ��� �Դϴ�. �ǹ̸� ������ ������

// "replace conditional with polymorphism"
// "����� �ڵ忡 ���(if, switch) �� �ִٸ� ������(�����Լ�) �� ������ ����"
//  ����������3.cpp => ����������4.cpp
//  ����������5.cpp => ����������6.cpp


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	virtual void draw() { std::cout << "draw shape\n"; }

	void set_color(int c) { color = c; }

	virtual int get_area() { return 0; }


	// �ڽ��� ���纻�� ����� �����Լ��� �׻� �����ϰ� ���˴ϴ�.
	virtual Shape* clone()
	{
		Shape* p = new Shape;   // ���ο� ������ �����
		p->color = this->color; // �ڽ��� ��� ����� ����
								// ����, �� �۾��� ��������ڷ��ص��˴ϴ�
		return p;
	}
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect\n"; }

	virtual Shape* clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle\n"; }

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

			// �������� OCP�� �����ϴ� ���� ���� �ڵ��̴�.!!
			// => �������� �ᱹ "�����Լ�" �̴�.

			v.push_back( v[k]->clone() ); // ������
							// k��° ������ ���� ���ʿ� ����.
							// ���ο� ������ �߰��Ǿ ���ڵ��
							// ������� �ʴ´�.(OCP)
							// don't ask do it.
		}
	}
}


