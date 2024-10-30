#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// Domain Name Server : url => ip 로 변경
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
        std::cout << "서버에 접속해서 "
            << url << "에 대한 IP 정보 얻는중\n";

        std::this_thread::sleep_for(std::chrono::seconds(3));

        return "100.100.100.100";
    }
};

// DNS의 대행자를 만들어 보자.
class DNSProxy : public IDNS
{
public:
    std::string resolve(const std::string& url)
    {
        if (url == "www.samsung.com")
        {
            // 자주 사용되는 url은 파일 등에 정보를 기록해 놓고,
            // 서버에 접속할 필요 없이 기록된 정보를 반환한다.
            return "100.100.100.100";
        }

        // Local PC에 정보가 없을 때만 실제 DNS 객체의 기능을 사용한다.
        DNS dns;
        return dns.resolve(url);
    }
};

int main()
{
    DNS dns;        // 항상 서버에 접근
    DNSProxy dns2;  // 캐쉬를 먼저 조사 후 정보가 없을 때만 서버에 접근

    std::cout << dns2.resolve("www.samsung.com") << std::endl;
}