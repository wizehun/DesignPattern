#define USING_GUI
#include "cppmaster.h"


class Window
{
    int handle;
public:
    void create(const std::string& title)
    {
        handle = ec_make_window(msgproc, title);
        ec_set_window_rect(handle, 0, 0, 500, 500);
    }

    // �ٽ� : �� �Ʒ� �Լ��� static �̾�� �ϴ��� ���� �ؾ� �մϴ�.
    // => ec_make_window() �� 1��° ���ڴ� ���ڰ� 4���� �Լ��ּ� �䱸
    // => ������ �Ϲ� ��� �Լ��� this �� �߰��ǹǷ� 5���� �˴ϴ�.
    // => static �̾�߸� ���ڰ� 4��
    // => ���, "C���� call back �Լ�"�� Ŭ������ ���鶧�� static �̾���Ѵ�.

    static int msgproc(int hwnd, int msg, int a, int b)
    {
        switch (msg)
        {
        case WM_LBUTTONDOWN: std::cout << "LBUTTON" << hwnd << std::endl; break;
        case WM_KEYDOWN:     std::cout << "KEYDOWN" << hwnd << std::endl; break;
        }
        return 0;
    }

};

int main()
{
    Window w;
    w.create("Title");

    ec_process_message();

}
