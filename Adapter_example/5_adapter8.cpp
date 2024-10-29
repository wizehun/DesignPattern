#include <iostream>
#include <list>
#include <vector>
#include <deque>

// adapter �� policy base design �� ����

template<typename T, typename C = std::deque<T> > class stack
{
	C c;
public:
	inline void push(const T& e) { c.push_back(e); }
	inline void pop()			  { c.pop_back(); }
	inline T& top()			  { return c.back(); }
};

#include <stack> // C++ ǥ���� stack �� ���� �����ϰ� �����Ǿ� �ֽ��ϴ�.
				 // ���� "stack adapter" ��� �θ��ϴ�.

int main()
{
	std::stack<int, std::list<int> > s3; // C++ ǥ�� stack

	stack<int, std::list<int> > s1;   // list �� stackó�� ����ϰڴٴ°�
	stack<int, std::vector<int> > s2; // vector �� stackó�� ����ϰڴٴ°�

	stack<int> s; // std::deque �� ����ϴ� ����

	s.push(10);
	s.push(20);
	s.pop();


}
