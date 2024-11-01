#define USING_GUI
#include "cppmaster.h"
#include <map>


// event ó���� �����Լ��� �ϸ�
// => �����Լ� ���̺��� ������尡 �ֽ��ϴ�.
// => 200�� �����Լ� * �Լ��ּ�ũ��(8����Ʈ) => 1600 ����Ʈ.


// �Ʒ� �ڵ尡 
// => CRTP �� ����ؼ� "������ �ƴ� �Լ�"�� �����Լ� ó�� �����ϰ� �ϴ� ���
// => MS �� WTL �� �̷��� ����
// => C++20 Range ���̺귯���� �̱���� ����

template<typename T>
class Window
{
    inline static std::map<int, Window*> this_map;

    int handle;
public:
    void create(const std::string& title)
    {
        handle = ec_make_window(msgproc, title);
        ec_set_window_rect(handle, 0, 0, 500, 500);

        this_map[handle] = this;
    }

    static int msgproc(int hwnd, int msg, int a, int b)
    {
        //		Window* self = this_map[hwnd];
        T* self = static_cast<T*>(this_map[hwnd]);

        switch (msg)
        {
        case WM_LBUTTONDOWN:
            self->lbutton_down();
            // �Լ� ȣ��
            // �����Լ� : dynamic binding (����ð��� �޸�����)
            // �񰡻�   : static binding(������ Ÿ��)
            break;

        case WM_KEYDOWN:
            self->key_down();
            break;
        }
        return 0;
    }

    void lbutton_down() {}
    void key_down() {}
};

class MainWindow : public Window< MainWindow>
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
