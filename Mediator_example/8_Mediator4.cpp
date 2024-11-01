#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
using namespace std::placeholders;


class NotificationCenter
{
    using HANDLER = std::function<void(void*)>;

    std::map<std::string, std::vector<HANDLER> > notif_map;
public:

    void addObserver(const std::string& key, HANDLER h)
    {
        notif_map[key].push_back(h);
    }
    void postNotificationWithName(const std::string& key, void* hint)
    {
        for (auto f : notif_map[key]) // notif_map[key] �� vector
        {
            f(hint);
        }
    }
};

void foo(void* p) { std::cout << "foo : " << (int)p << std::endl; }
void goo(void* p, int a)
{
    std::cout << "goo : " << (int)p << std::endl;

    if (a == 11)
        std::cout << "���͸�����\n";
    else if (a == 12)
        std::cout << "disconnect wifi\n";
}

int main()
{
    // IOS ���̺귯���� �ִ� �뺸 ����
    NotificationCenter nc;

    nc.addObserver("LOWBATTERY", &foo);
    nc.addObserver("LOWBATTERY", std::bind(&goo, _1, 11));
    nc.addObserver("DISCONNECT_WIFI", std::bind(&goo, _1, 12));

    // ���͸� ����ʿ��� ���͸��� ����������
    nc.postNotificationWithName("LOWBATTERY", (void*)30);
}



