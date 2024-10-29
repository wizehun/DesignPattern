#include <iostream>
#include <list>
#include <vector>
#include <deque>

// �ذ�å #1. private ���
// private ��� : ��� Ŭ������ ��� ����� private ������ ����� �޶�.
// public ��� : ���ټӼ��� �������� ����.
template<typename T> class stack : private std::list<T>
{
public:
	void push(const T& e) { std::list<T>::push_back(e); }
	void pop()			  { std::list<T>::pop_back(); }
	T& top()			  { return std::list<T>::back(); }
};

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.pop();

	s.push_front(0); // error. private ����̹Ƿ�
					 // private ���

}
