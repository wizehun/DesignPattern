#define USING_GUI
#include "cppmaster.h"
#include <map>

// Ŭ���� ���ø� ���鶧
// => "T" �� ������� �ʴ� �����
// => ���ø��� �ƴ� ��� Ŭ������ �����
// => �װ����� �ۼ��ؾ� �մϴ�.
// => "Thin Template" �Ǵ� "Template hositing" �̶�� �̸��� ������ ���
//    ���ø� ���� �ڵ�޸𸮸� ���̱� ���� ���Ǵ� ���

class Window  // �ٽ� tempate �ƴ�.
{
protected:
    inline static std::map<int, Window*> this_map;
    int handle;
public:
    void move() {}
    void show() {}
    void set_window_title() {}

    void lbutton_down() {}
    void key_down() {}
};

template<typename T>
class MsgWindow : public Window
{
public:
    void create(const std::string& title)
    {
        handle = ec_make_window(msgproc, title);
        ec_set_window_rect(handle, 0, 0, 500, 500);
        this_map[handle] = this;
    }
    static int msgproc(int hwnd, int msg, int a, int b)
    {
        T* self = static_cast<T*>(this_map[hwnd]);

        switch (msg)
        {
        case WM_LBUTTONDOWN:
            self->lbutton_down();
            break;

        case WM_KEYDOWN:
            self->key_down();
            break;
        }
        return 0;
    }

};

class MainWindow : public MsgWindow< MainWindow>
{
public:
    void lbutton_down()
    {
        std::cout << "MainWindow lbutton_down\n";
    }
};


int main()
{
    MainWindow w1;
    w1.create("MainWindow");

    ec_process_message();

}
