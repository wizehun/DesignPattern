#include <iostream>
#include <string>
#include <vector>

class TextView
{
	std::string data;
public:
	TextView(const std::string& s) : data(s) {}

	void show() { std::cout << data << std::endl; }
};







//=================================================
class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};

// ������� ����
// Ŭ���� ����� : Ŭ������ �������̽� ����
// ��ü   ����� : ��ü��   �������̽� ����

class Text : public TextView,	public Shape       
{
public:
	Text(const std::string& data) : TextView(data) {}

	void draw() override
	{
		TextView::show();
	}
};

// ��ü ����͸� ����� ���ô�.
class ObjectAdapter : public Shape
{
	TextView* tview; // �ٽ� : ������ �Ǵ� ���� ��� ����Ÿ
					 // �ǵ� : �̹� ������ ��ü�� ����Ű�ڴ�
public:
	ObjectAdapter(TextView* t) : tview(t) {}

	void draw()
	{
		tview->show();
	}
};







int main()
{
	std::vector<Shape*> v;

	TextView tv("hello"); // TextView : Ŭ����(����Ÿ Ÿ��)
						  // tv        : ��ü(����)

	// �̹� ������ ��ü tv �� v �� ������ ������� ?
//	v.push_back(&tv); // error

	// tv �� v�� �ֱ� ���� Text �� ����Ҽ� ������ ?
	// => �ȵ˴ϴ�. Text �� Ŭ���� �����


	v.push_back( new ObjectAdapter(&tv) );
				// ������  !!

	v[0]->draw(); // tv.show()
}







