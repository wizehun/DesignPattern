#include <iostream>
#include <string>
#include <vector>
#include <stack>

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
//--------------------------------------------------
struct ICommand
{
    virtual void execute() = 0;
    virtual bool can_undo() { return false; }
    virtual void undo() {}

    virtual ~ICommand() {}
};

// ������ �߰��ϴ� ����� ���������� ���� �ֽ��ϴ�.
// "��� Ŭ����"�� ���� �����մϴ�.
class AddCommand : public ICommand
{
    std::vector<Shape*>& v;
public:
    AddCommand(std::vector<Shape*>& v) : v(v) {}

    void execute() override { v.push_back(create_shape()); }

    bool can_undo() override { return true; }

    void undo() override
    {
        Shape* s = v.back();
        v.pop_back();
        delete s;
    }

    // �Ʒ� �ڵ�� template method �� �������� ���� �Դϴ�.
    // �׷���, �����Լ��� �ϴ� ��(�Ļ� Ŭ������ �����ϴ� ��)��
    // "��ü�� ����(Ÿ��)" �� ����

    // factory method ��� �մϴ�.
    // => ��ü�� �����ϱ� ���� �������̽��� �����ϰ� ���������
    //    ��ü�� ������ �Ļ�Ŭ������ ����
    //    template method �� ������ ����

    virtual Shape* create_shape() = 0;
};


class AddRectCommand : public AddCommand
{
public:
    AddRectCommand(std::vector<Shape*>& v) : AddCommand(v) {}

    Shape* create_shape() override { return new Rect; }
};


class AddCircleCommand : public AddCommand
{
public:
    AddCircleCommand(std::vector<Shape*>& v) : AddCommand(v) {}

        // �� �����ڴ� �ڽ��� ���� ���ڸ� ��� Ŭ������ ������ �ϸ� �մϴ�.
        // => �̷����� ������ ��� ������ ����ϸ� �˴ϴ�.

        // ������ ��� ���� - ��� Ŭ���� �����ڸ� ����� �޶�
    using AddCommand::AddCommand;

    Shape* create_shape() override { return new Circle; }
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

    std::stack<ICommand*> undo_stack;
    std::stack<ICommand*> redo_stack;

    ICommand* command = nullptr;

    while (1)
    {
        int cmd;
        std::cin >> cmd;

        if (cmd == 1)
        {
            command = new AddRectCommand(v);
            command->execute();

            undo_stack.push(command);
        }
        else if (cmd == 2)
        {
            command = new AddCircleCommand(v);
            command->execute();

            undo_stack.push(command);
        }
        else if (cmd == 9)
        {
            command = new DrawCommand(v);
            command->execute();

            undo_stack.push(command);
        }

        else if (cmd == 0)
        {
            if (!undo_stack.empty())
            {
                command = undo_stack.top();
                undo_stack.pop();

                if (command->can_undo())
                {
                    command->undo();
                }

                delete command;
            }
        }
    }
}
