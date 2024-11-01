#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>


class Window
{
    inline static std::map<int, Window*> this_map;

    int handle;

    Window* parent = nullptr;
    std::vector<Window*> child_vector;
public:
    void add_child(Window* child)
    {
        child->parent = this;

        child_vector.push_back(child);
        ec_add_child(this->handle, child->handle);

        ec_set_window_rect(child->handle, 100, 100, 200, 200); // �ڽ������� ũ�⺯��
    }


    void create(const std::string& title)
    {
        handle = ec_make_window(msgproc, title);
        ec_set_window_rect(handle, 0, 0, 500, 500);

        this_map[handle] = this;
    }

    static int msgproc(int hwnd, int msg, int a, int b)
    {
        Window* self = this_map[hwnd];

        switch (msg)
        {
        case WM_LBUTTONDOWN:
            self->fire_lbutton_down();
            break;

        case WM_KEYDOWN:
            self->key_down();
            break;
        }
        return 0;
    }

    // �Ʒ� �ڵ尡 "å���� �� ����" �� �ٽ�
    void fire_lbutton_down()
    {
        // #1. �ڽ��� ���� ó��
        if (lbutton_down() == true)
            return;

        // #2. ó�� ���� ���� ��� �θ� ����
        if (parent != nullptr)
            parent->fire_lbutton_down();
    }

    virtual bool lbutton_down() { return false; }
    virtual void key_down() {}
};





class MainWindow : public Window
{
public:
    bool lbutton_down() override
    {
        std::cout << "MainWindow lbutton_down\n";
        return true;
    }
};
class ImageView : public Window
{
public:
    bool lbutton_down() override
    {
        std::cout << "ImageView lbutton_down\n";

        // return true;	// �̺�Ʈ ó���� ������ �޶�.

        return false;	// �̺�Ʈ�� �θ������쿡�� ���� �޶�.
    }

};


int main()
{
    MainWindow w1;
    w1.create("MainWindow");

    ImageView w2;
    w2.create("ImageView");

    w1.add_child(&w2);

    ec_process_message();

}

// C# WPF �� ���� ���� �̺�Ʈ ó����
// "Bubbling Event" ��� �� ���

// C++ MFC : Command Routing �̶�� �ϰ�

// Swift IOS : Responder Chain �̶�� �մϴ�