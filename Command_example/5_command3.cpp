#include <iostream>
#include <string>
#include <vector>

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

struct ICommand
{
    virtual void execute() = 0;
    virtual bool can_undo() { return false; }
    virtual void undo() {}

    virtual ~ICommand() {}
};

class AddRectCommand : public ICommand
{
    std::vector<Shape*>& v;
public:
    AddRectCommand(std::vector<Shape*>& v) : v(v) {}

    void execute() override
    {
        v.push_back(new Rect); // �簢���� �߰��ϴ� command
    }

    bool can_undo() override { return true; } // ��� ������ Ÿ�� (���Ϳ��� ����� ��)

    void undo() override
    {
        Shape* s = v.back();
        v.pop_back();
        delete s;   // ���� �ֱٿ� �߰��� ��(��ü)�� ����
    }
};

class AddCircleCommand : public ICommand
{
    std::vector<Shape*>& v;
public:
    AddCircleCommand(std::vector<Shape*>& v) : v(v) {}

    void execute() override { v.push_back(new Circle); }

    bool can_undo() override { return true; }

    void undo() override
    {
        Shape* s = v.back(); // ��ȯ��
        v.pop_back();		 // ����
        delete s;
    }
};

class DrawCommand : public ICommand
{
    std::vector<Shape*>& v;
public:
    DrawCommand(std::vector<Shape*>& v) : v(v) {}

    void execute() override
    {
        for (auto e : v)
            e->draw();
    }

    bool can_undo() override { return true; }

    void undo() override
    {
        system("cls");
    }
};

int main()
{
    std::vector<Shape*> v;

    ICommand* command = nullptr;

    while (1)
    {
        int cmd;
        std::cin >> cmd;

        if (cmd == 1)
        {
            command = new AddRectCommand(v);
            command->execute();
        }
        else if (cmd == 2)
        {
            command = new AddCircleCommand(v);
            command->execute();
        }
        else if (cmd == 9)
        {
            command = new DrawCommand(v);
            command->execute();
        }
    }
}