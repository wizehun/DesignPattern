#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Stream
{
	virtual void write(const std::string&) = 0;
	virtual ~Stream() {}

};

class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void write(const std::string& s)
	{
		printf("%s ����\n", s.c_str());
	}
};

int main()
{
	// ���Ͽ� ���� "��ȣȭ" �ϴ� ����� �ʿ� �մϴ�.
	// ���̺귯�� ������ ���忡�� "�ּ��� ������"�� ������ ���ô�.

	// #1. FileStream �� �Ļ� Ŭ������ "EncrpytStream" �� ������
	// ���� 1. FileStream �� �ƴ϶� NetworkStream �� �Ļ� Ŭ������ �ʿ�
	// ���� 2. ��ȣȭ �� �ƴ϶� ���൵ �ʿ� �ϴٸ� �ٽ� �Ļ�Ŭ���� �ʿ�
	//        => ��ȣȭ ������ ���ÿ� �ʿ��ϸ� �ٽ� ���(���߻��) �ʿ�

	// #2. ��� Ŭ������ Stream �� "��ȣȭ ���" �߰�
	// ���� : �ʿ���� Stream ���� ��� ���� �ް� �ǰ�
	//        ��� Ŭ������ ������ ��� �ҽ��� �ٽ� ������
	//        �׸���, OCP ����
	//        ���ο� �䱸������ ���涧���� "���� �ڵ� ����"

	// #3. Decorator ������ ����ϸ� ��� ?

	FileStream fs("a.txt");
	fs.write("hello");
	
	EncrpytDecorator ed(&fs);
	ed.write("hello");  // 1. ����Ÿ�� ��ȣȭ �ϰ�
						// 2. fs.write(��ȣȭ�ȵ���Ÿ)

	ZipDecorator zd(&ed);
	zd.write("hello");	// 1. �����ϰ�
						// 2. ed.write(����ȵ���Ÿ)�� ��ȣȭ
						// 3. fs.write(�����ȣȭ�ȵ���Ÿ)
}
