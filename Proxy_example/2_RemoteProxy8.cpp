#include <memory>
#include "ICalc.h"

int main()
{
    // C++ ǥ�ؿ� �ִ� "std::shared_ptr" �� ����ϸ� �ȵǳ��� ?

    std::shared_ptr<ICalc> p1(load_proxy());
    // p1 �� �Ҹ��ڿ��� " delete " �մϴ�.
    // �ᱹ DLL ���� new �Ѱ��� exe ���� delete �Ѱ�
    // �츮�� ���ϴ� ���� delete �ƴ϶� Release() ȣ��

    sp<ICalc> p2(load_proxy());
    // p2 �� �Ҹ��ڿ��� "������������->Release()" ȣ��
    // ��, DLL ���ο��� delete!!!

// �׷���, C++ǥ�ؿ� ����Ʈ�����Ͱ� �̹� ������
// ���� ���� ������, ���� ���¼ҽ��� �ڽŸ��� ����Ʈ �����͸� �������
}