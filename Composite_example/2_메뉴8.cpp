#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class unsupported_operation {};

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title)
		: title(title) {}

	virtual ~BaseMenu() {}

	std::string get_title() { return title; }

	virtual void command() = 0;

	// �Ʒ� 2���� ��� �Լ��� "PopupMenu" �� �ʿ� �մϴ�.
	// �׷���, ������� ���Ǽ��� ����ؼ�
	// BaseMenu ���� ���� ����

	// �Ʒ� ó�� ����� �ʿ����  "MenuItem" ������ ������ �����ؾ� �մϴ�.
//	virtual void add(BaseMenu*) = 0;
//	virtual BaseMenu* submenu(int idx) = 0;


	// �⺻ ���� : ���� �߻�
	virtual void add(BaseMenu*) { throw unsupported_operation(); }
	virtual BaseMenu* submenu(int idx) { throw unsupported_operation(); }

};




class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id)
		: BaseMenu(title), id(id) {}



	void command()
	{
		std::cout << get_title() << " �޴� ����\n";
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title)
		: BaseMenu(title) {}

	void add(BaseMenu* m) { v.push_back(m); }


	void command()
	{
		while (1)
		{
			system("cls");

			auto sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << '\n';
			}
			std::cout << sz + 1 << ". ����\n";

			std::cout << "�޴��� �����ϼ��� >> ";



			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;


			v[cmd - 1]->command();

		}
	}

	BaseMenu* submenu(int idx) { return v[idx]; }
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("���� ����");
	PopupMenu* pm2 = new PopupMenu("�ػ� ����");

	root->add(pm1);
	root->add(pm2);
	root->add(new MenuItem("�����", 12));
	//------------------------------

	auto m1 = root->submenu(0); 


	// ĳ���� ���� ���!!!
	root->submenu(1)->add(new MenuItem("HD", 21));
			// ok.. ������

	try
	{

		root->submenu(2)->add(new MenuItem("HD", 21));
		// �������� ������, 
		// MenuItem �� ���� add ȣ���̹Ƿ�
		// ����� ����
	}
	catch (unsupported_operation& e)
	{
		std::cout << "���� �߻�\n";
	}

	root->command();

}



// ������ ���� : ������ �߻��ϹǷ� "����"�ϴ�.
// ��Ÿ�� ���� : ������ ������ ���¿����� �߻��Ҽ� �����Ƿ� �������� �ʴ�.

// �޴� 7.cpp : �������� �߽��ϴ� ��
// �޴� 8.cpp : ���Ǽ��� �߽��ϴ� ��

// => 2�� ��� �θ� ����ϰ�, ������� �ֽ��ϴ�.

// => python, C#, java �� ����ϱ� ���� ������ "�޴�8" ������� 
//   ���� �Ǿ� �ֽ��ϴ�.