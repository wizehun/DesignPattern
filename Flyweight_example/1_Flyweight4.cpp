// godbolt.org
#include <iostream>

int main()
{
    // #1.
//	printf("hello\n");	// 1. ����޸𸮿� "hello" ���ڿ� �����
                        // 2. mov  edi, "����޸��� ���ڿ��ּ�"
                        // 3. call printf


    // #2. ���ڿ� �迭 vs ���ڿ� ������
    char sa[] = "abcd";
    //	char* sp  = "abcd"; // C ok. C++ error

    *sa = 'x'; // ok. stack �� ����, R/W ����
    //	*sp = 'x'; // C ���. runtime error

    const char* sp = "abcd"; // C++ ok
    // ��, �ݵ�� const �ʿ�


// #3. flyweight
    char sa1[] = "abcd";
    char sa2[] = "abcd";

    const char* sp1 = "abcd";
    const char* sp2 = "abcd";

    printf("%p, %p\n", sa1, sa2); // �ٸ� �ּ�
    printf("%p, %p\n", sp1, sp2); // ���� �ּ�(����)
}

// ���α׷����� �б⸸ �ϴ� ���ڿ��� �ʿ��ϸ�
// ���ڿ� �迭�� �ƴ� ���ڿ� ������ ���

// C++ 
// std::string : ���ڿ� ����(�����Ҵ��ؼ� ����)
// std::string_view : const char* �� ������ ��Ȱ (���ڿ� ������)

// Rust
// str Ÿ�� : const char*
// String  : std::string �� ����. 
