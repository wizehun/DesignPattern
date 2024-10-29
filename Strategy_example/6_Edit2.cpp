// 33 page ~ 
#include <iostream>
#include <string>
#include <conio.h>

// �ٽ� #1. validation ��å�� ����ڰ� �����Ҽ� �־�� �Ѵ�.

// �ٽ� #2. ���ϴ� ���� �����Լ���...


class Edit
{
	std::string data;
public:

	// ���뼺�� �������� �и�
	// => ������ ���� �帧 ������ ���ϴ� ���� ã�ƶ�
	// => ���ϴ� ���� �����Լ��� �и�

	virtual bool validate(char c)
	{
		return true;
	}


	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch(); 

			if (c == 13) break; 

			if ( validate(c) ) // ���� ��ȿ�� Ȯ���� �����Լ��� ���ؼ�!
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

// ���� Edit ����ڴ�
// Validation ��å�� �����Ϸ��� "Edit" �Ļ�Ŭ������ �����
// ��ӵ� �����Լ��� override �ϸ�˴ϴ�.
class NumEdit : public Edit
{
public:
	bool validate(char c) override
	{
		return isdigit(c);
	}
};

int main()
{
//	Edit e;
	NumEdit e;

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


