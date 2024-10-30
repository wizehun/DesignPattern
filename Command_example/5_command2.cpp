#include "monitor.h"

// 명령은 여러개가 필요 합니다.
// 인터페이스를 먼저 제공
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
    m.set_brightness(90);		// 직접 변경

    // m의 밝기 상태를 이전 상태로 복구해 보세요
    m.set_brightness(old);


    BrightCommand cmd(m, 90);
    cmd.execute();				// 객체 사용
    cmd.undo();
}