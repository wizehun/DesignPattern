// 33 page ~ 
#include <iostream>
#include <string>
#include <conio.h>

// ���ϴ� ���� �и��ϴ� 2���� ���
// #1. ���ϴ� ���� �����Լ��� - template method ����,  Edit2.cpp �ҽ�
// #2. ���ϴ� ���� �ٸ� Ŭ������ - strategy ����.      Edit3.cpp


// Validation ��å�� ������ Ŭ������ ����
// => ��ü �����ؾ� �ϹǷ� "���Ѱ���"
// => �������̽��� ���� ����

struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool is_complete(const std::string& s) { return true; }
	virtual ~IValidator() {}
};

// �ֹε�Ϲ�ȣ : 931  1  Ȯ��




class Edit
{
	std::string data;

	IValidator* val = nullptr;		// ���� ��ȿ��Ȯ�ο� ����Ұ�ü
public:
	void set_validator(IValidator* v) { val = v; }


	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch(); 

			if (c == 13 && (val == nullptr || val->is_complete(data))   ) break;

			if ( val == nullptr || val->validate(data, c) ) // ��ȿ�����θ� �ٸ� ��ü�� ����
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

// ���� Edit ���� ����� �پ��� "Validator ��ü(��ȿ�� Ȯ�� ������ ���� Ŭ����)"
// �� ����� �˴ϴ�.
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
/*
class email_validator : public IValidator {};
class pinnumber_validator : public IValidator {};
class phonenumber_validator : public IValidator {};
*/

int main()
{
	Edit e;

	LimitDigitValidator v(5);
	e.set_validator(&v); // �ٽ� 

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


