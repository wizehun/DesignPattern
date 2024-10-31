#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};


class ShapeFactory
{
    MAKE_SINGLETON(ShapeFactory)

        using CREATOR = Shape * (*)();

    inline static std::map<int, CREATOR> create_map;

public:
    void register_shape(int key, CREATOR c)
    {
        create_map[key] = c;
    }

    Shape* create(int key)
    {
        Shape* p = nullptr;

        auto it = create_map.find(key);

        if (it != create_map.end())
        {
            p = it->second();
        }
        return p;
    }
};



// ���忡 ������ �ڵ�����ϴ� Ŭ���� 
// => �����ڸ� ���
struct AutoRegister
{
    AutoRegister(int key, Shape* (*f)())
    {
        ShapeFactory::get_instance().register_shape(key, f);
    }
};

// ���� ������ �����ڰ� ���� ȣ��Ǵ��� ������ ������
// => ��� ���������� �����ڴ� main �Լ� ������ ȣ��
// AutoRegiter ar(1, &Rect::create);





class Rect : public Shape
{
public:
    void draw() override { std::cout << "draw Rect" << std::endl; }

    static Shape* create() { return new Rect; }

    // static ��� ����Ÿ�� Ư¡�� ������ ������
    // => ��ü�� �Ѱ��� ������ �ʾƵ� �޸𸮿� �����˴ϴ�
    // => ���α׷� ó�� ����� �����˴ϴ�.(�ᱹ ��������)
    // => ��, main �Լ� ������ ar ������ ȣ��. 
    static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::create);

/*
// �Ʒ� ���� ������ ������
                        // Rect::ar �� ������ ȣ��
                        //		(�ᱹ Ŭ������ ���ؼ� �ѹ� ȣ��)
Rect* r1 = new Rect;	// Rect ������ ȣ��
Rect* r2 = new Rect;	// Rect ������ ȣ��
Rect* r2 = new Rect;	// Rect ������ ȣ��
                        // �����ڴ� ��ü�� �ѹ��� ȣ��

// C# ���� static �����ڶ�� ������ �ֽ��ϴ�.
class Car
{
    public Car() {} // instance ������
    static Car() {} // static ������, ���������� ǥ�� ����
};

Car c1 = new Car(); // static ������ ȣ��
                    // instance ������ ȣ��
Car c2 = new Car(); // instance ������ ȣ��
*/

class Circle : public Shape
{
public:
    void draw() override { std::cout << "draw Circle" << std::endl; }

    static Shape* create() { return new Circle; }


    // C++17 inline static ���� �ϸ� �ܺ� ���� ��� ��
    // ��, Ŭ���� �ȿ����� () �� �ƴ� {} �ʱ�ȭ ���
    inline static AutoRegister ar{ 2, &Circle::create };
};





int main()
{
    std::vector<Shape*> v;

    ShapeFactory& factory = ShapeFactory::get_instance();

    // �̹� �� ������ static ����� ar �� �����ڿ��� ���忡 ��� �Ϸ�!!
//	factory.register_shape(1, &Rect::create);
//	factory.register_shape(2, &Circle::create);

    while (1)
    {
        int cmd;
        std::cin >> cmd;

        if (cmd > 0 && cmd < 8)
        {
            Shape* s = factory.create(cmd);

            if (s != nullptr)
                v.push_back(s);

        }
        else if (cmd == 9)
        {
            for (int i = 0; i < v.size(); i++)
            {
                v[i]->draw();
            }
        }
    }
}



