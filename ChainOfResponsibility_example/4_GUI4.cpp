// GUI1.cpp
// => 32bit(x86) ���� �����ؾ� �մϴ�

// 1. ��κ��� OS �� GUI �� ����� ���� �Լ� ����(C �����)
// 2. GUI ���α׷��� ����� ���� �⺻���� ����� "C�Լ�" ���
// 3. �׷���, C�Լ� �� ��������ϸ� ���� �����մϴ�.

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

    static int msgproc(int hwnd, int msg, int a, int b)
    {
        switch (msg)
        {
        case WM_LBUTTONDOWN:
            lbutton_down();		// ��� �Լ��� "��ü.�Լ�()" ���Ǿ���մϴ�
                                // ���� ���ڵ��
                                // "this->lbutton_down()" �Ǿ�� �մϴ�.
                                // �׷���, static ��� �Լ�������
                                // this�� ���⶧���� ����
                                // error.
                                // �ذ�å�� "�����ҽ�"
            break;

        case WM_KEYDOWN:     key_down();      break;
        }
        return 0;
    }

    virtual void lbutton_down() {}
    virtual void key_down() {}
};


int main()
{
    Window w;
    w.create("Title");

    ec_process_message();

}
