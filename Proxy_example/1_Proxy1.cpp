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

int main()
{
	DNS dns;

	std::cout << dns.resolve("www.samsung.com") << std::endl;
}