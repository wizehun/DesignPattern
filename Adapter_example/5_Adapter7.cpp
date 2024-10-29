#include <iostream>
#include <list>
#include <vector>
#include <deque>

// �ذ�å #2. ����� �ƴ� ����

template<typename T> class stack 
{
	std::list<T> c;
public:
	void push(const T& e) { c.push_back(e); }
	void pop()			  { c.pop_back(); }
	T& top()			  { return c.back(); }
};
int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.pop();

	s.push_front(0); // error. push_front() �Լ� ����. 

}

// ����
// => ��� Ŭ���� �Լ��� �ܺ� ���� ���Ϸ��� "����" �ϸ� �Ǵµ�
// => �� private ����� ����ϳ��� ??

class stack : private list {};
				// => ����̹Ƿ� list �����Լ��� override �Ҽ� �ִ�.
class stack
{
	list c;	// => ������ list �����Լ��� override �Ҽ� ����.
};

// ���� ������ ������ �����ϴ�.
// => stack �� list �� �Ϻ� ��ɸ� ���������� ���
// => �ܺ� �������ʿ�����Ƿ�