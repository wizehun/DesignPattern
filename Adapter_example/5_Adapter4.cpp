#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL �� Adapter
// 1. C++ ǥ�� ���̺귯���� STL ���� �̹� list�� �ֽ��ϴ�.
// 2. �׷���, stack �� �ʿ��մϴ�.(�̹� ������ ���ٰ� ����)

int main()
{
	// ��� #1. ���� ��� �ȴ�. list �� �������θ� ����ϸ� �ȴ�.
	std::list<int> s;

	// list�� �������θ� ����/����
	s.push_back(10);
	s.push_back(20);

	s.pop_back();

	// ���� #1. �������� ���� �ʴ�.( stack �� �ƴ� list ó�� ���δ�)
	//     #2. �Ǽ��� �տ� �������� �ִ�.
	s.push_front(0);// �Ǽ�
}
