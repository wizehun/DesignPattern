#include "monitor.h"

// ����� �������� �ʿ� �մϴ�.
// �������̽��� ���� ����
struct ICommand
{
    virtual void execute() = 0;
    virtual bool can_undo() { return false; }
    virtual void undo() {}

    virtual ~ICommand() {}
};

class BrightCommand : public ICommand
{
    Monitor& m;
    int value;
    int old = 0;
public:
    BrightCommand(Monitor& m, int v) : m(m), value(v) {}

    void execute()
    {
        old = m.get_brightness();
        m.set_brightness(value);
    }

    bool can_undo() { return true; }

    void undo()
    {
        m.set_brightness(old);
    }
};

int main()
{
    Monitor m;

    int old = m.get_brightness();
    m.set_brightness(90);		// ���� ����

    // m�� ��� ���¸� ���� ���·� ������ ������
    m.set_brightness(old);


    BrightCommand cmd(m, 90);
    cmd.execute();				// ��ü ���
    cmd.undo();
}