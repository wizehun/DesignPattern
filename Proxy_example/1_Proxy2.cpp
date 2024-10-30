#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// Domain Name Server : url => ip �� ����
struct IDNS
{
    virtual std::string resolve(const std::string& url) = 0;
    virtual ~IDNS() {}
};

class DNS : public IDNS
{
public:
    std::string resolve(const std::string& url)
    {
        std::cout << "������ �����ؼ� "
            << url << "�� ���� IP ���� �����\n";

        std::this_thread::sleep_for(std::chrono::seconds(3));

        return "100.100.100.100";
    }
};

// DNS�� �����ڸ� ����� ����.
class DNSProxy : public IDNS
{
public:
    std::string resolve(const std::string& url)
    {
        if (url == "www.samsung.com")
        {
            // ���� ���Ǵ� url�� ���� � ������ ����� ����,
            // ������ ������ �ʿ� ���� ��ϵ� ������ ��ȯ�Ѵ�.
            return "100.100.100.100";
        }

        // Local PC�� ������ ���� ���� ���� DNS ��ü�� ����� ����Ѵ�.
        DNS dns;
        return dns.resolve(url);
    }
};

int main()
{
    DNS dns;        // �׻� ������ ����
    DNSProxy dns2;  // ĳ���� ���� ���� �� ������ ���� ���� ������ ����

    std::cout << dns2.resolve("www.samsung.com") << std::endl;
}