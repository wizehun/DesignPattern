// 5_���丮�޼ҵ�
#include <iostream>

// ��� ������ ��Ʈ���� ������ ��� Ŭ���� �ʿ�
struct IButton
{
    virtual void Draw() = 0;
    virtual ~IButton() {}
};
struct IEdit
{
    virtual void Draw() = 0;
    virtual ~IEdit() {}
};


struct WinButton : public IButton
{
    void Draw() { std::cout << "Draw WinButton" << std::endl; }
};
struct WinEdit : public IEdit
{
    void Draw() { std::cout << "Draw WinEdit" << std::endl; }
};

struct OSXButton : public IButton
{
    void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
struct OSXEdit : public IEdit
{
    void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
//--------------------------------------
// factory method �� �ƴ� template ����

// �� ��Ÿ�Ϻ� ��Ʈ�� �̸��� �����ϴ� Ÿ�� ����
struct WinStyle
{
    using Button = WinButton;  // typedef WinButton Button
    using Edit = WinEdit;

    // �׿� ��� ��Ʈ���� �̸� ����
};
struct OSXStyle
{
    using Button = OSXButton;
    using Edit = OSXEdit;
};




template<typename T>
class Dialog
{
public:
    void init()
    {
        // ���� T �� ��Ʈ���� �̸��� �ƴ�
        // ��Ʈ���� �̸��� �����ϴ� Ÿ��
        // => ��, ���� �̸��� �Ѱ��� Ÿ������ ���� ������
        IButton* btn = new typename T::Button;
        IEdit* edit = new typename  T::Edit;

        // btn->Move(); edit->Move();

        btn->Draw();
        edit->Draw();
    }

};

int main(int argc, char** argv)
{
    Dialog<OSXStyle> dlg1;
    Dialog<WinStyle> dlg2;

    dlg1.init();
    dlg2.init();
}







