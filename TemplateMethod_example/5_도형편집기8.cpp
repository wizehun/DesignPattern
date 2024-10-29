#include <iostream>
#include <vector>

//���ܷ� ����ϱ� ���� Ÿ��
class unsupported_operation {};

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void draw()
	{
		std::cout << "lock mutex\n";
		draw_imp();
		std::cout << "unlock mutex\n";

	}

	void set_color(int c) { color = c; }

	// ���� �Լ�    : �Ļ� Ŭ������ override ���� ������ �⺻ ���������Ѵٴ� �ǵ�
	// ���� �����Լ� :�Ļ� Ŭ������ "�ݵ�� �����" �� �����ϴ� ��

protected:
	virtual void draw_imp() = 0;


public:
	// clone �� ��쵵 "������ ����" �Ҽ��� �����ϴ�.
	// #1. ���� �����Լ��� �ص� �����ϴ�.
	//    => ���� �����Լ��� ��������, �Ļ�Ŭ������ ���Ѿ� �ϴ� ��Ģ�� �������ϴ�.
	// 
	// #2. �Ʒ�ó�� �Ҽ��� �ֽ��ϴ�.
	//    => �⺻ �������� ���� �߻�
	//    => C#, Python���� �θ� ���Ǵ� ������ ���

	// 1. �Ļ�Ŭ�������� override ���� �ʰ�, ��뵵 ���� ������ ok
	// 2. �Ļ�Ŭ�������� override ���� �ʰ�, ����ߴٸ�, ���� �߻�. runtime error
	// 3. �Ļ�Ŭ�������� override �ϰ� ����ϸ� ok. 
	virtual Shape* clone() { throw unsupported_operation(); }



	// �Ʒ� ��쵵
	// 1. ���� �����Լ��� ������ �ʰ�
	// 2. ���� ������ ����� ����
	// 3. �߸��� ������ ��ӵȰ��� �����ϴ�(C���)�� �θ� ���
	virtual int get_area() { return -1; }

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


