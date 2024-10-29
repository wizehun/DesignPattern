#include <iostream>
#include <string>
#include <conio.h>

// Validation ��å�� �ٸ� Ŭ������ ����
struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool is_complete(const std::string& s) { return true; }
	virtual ~IValidator() {}
};

class LimitDigitValidator : public IValidator
{
	int limit;
public:
	LimitDigitValidator(int n) : limit(n) {}

	bool validate(const std::string& s, char c) override
	{
		return s.size() < limit && isdigit(c);
	}

	bool is_complete(const std::string& s) override
	{
		return s.size() == limit;
	}
};



class Edit
{
	std::string data;

	IValidator* val = nullptr;		
public:
	void set_validator(IValidator* v) { val = v; }


	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13 && (val == nullptr || val->is_complete(data))) break;

			if (val == nullptr || val->validate(data, c)) // ��ȿ�� ������ Ȯ���� �ٸ� ��ü�� ����
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};



int main()
{
	Edit e;

	LimitDigitValidator v(5);
	e.set_validator(&v); 

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


