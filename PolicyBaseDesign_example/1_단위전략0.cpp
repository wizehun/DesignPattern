#include <cstdlib>

// C++ ������ �پ��� �޸� �Ҵ� ����� �ֽ��ϴ�.

int main()
{
	// #1. new/delete
	int* p1 = new int;
	delete p1;


	// #2. malloc/free
	int* p2 = static_cast<int*>(malloc(sizeof(int)));
	free(p2);


	// #3. system call �� ���� ����ϴ� ���
	// => ���Ҵ�, ���� �޸� ����
	// linux : brk(), mmap()
	// windows : HeapAlloc(), VirtualAlloc()


	// #4. pooling �����..
	// => �޸� �Ҵ�/������ ������ ȿ����(�޸� fragmentation ����)�ϱ� ���� ���
}