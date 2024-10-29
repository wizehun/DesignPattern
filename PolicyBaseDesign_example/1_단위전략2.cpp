#include <iostream>
#include <cstdlib>

// ��� #1. template method ���� ���
// => ���ϴ� ��(�޸� �Ҵ�/���� ���)�� �����Լ��� �и����ڴ� ��

// ����
// => �޸� �Ҵ�/���� �˰����� "vector�� �Ļ�Ŭ���� (MallocVector)"�� �����ϰ� �ȴ�.
// => ��, list, set, map ��� �޸� �Ҵ� �˰����� �����ϰ� �����Ϸ���
//    �����ϰ� �Ļ� Ŭ������ ���� �ٽ� �Ҵ� �˰����� �ۼ��ؾ� �Ѵ� !

template<typename T>
class vector
{
    T* buff = nullptr;
    int size;
public:
    // #1. �޸� �Ҵ�/������ å������ �����Լ� ����
    virtual T* allocate(std::size_t sz) { return new T[sz]; }
    virtual void deallocate(T* p, std::size_t sz) { delete[] p; }

    // #2. vector �� ��� ��� �Լ����� �޸� �Ҵ�/����
    //     �� �ʿ��ϸ� allocate/deallocate �����Լ� ���
    vector(int sz) : size(sz)
    {
        buff = allocate(sz);
        //....
    }
    ~vector()
    {
        deallocate(buff, size);
        //....
    }
};

// �ٽ� : �޸� �Ҵ� & ���� �� �����Ϸ��� �Ļ� Ŭ������ ����� �ȴ�.
// (�����Լ��� �����ϱ� ���� Ŭ����)
template <typename T>
class MallocVector : public vector<T>
{
public:
    T* allocate(std::size_t sz) override
    {
        return static_cast<T*>(malloc(sizeof(T) * sz));
    }
    void deallocate(T* p, std::size_t sz) override
    {
        free(p);
    }
};

int main()
{
    vector<int> v(4);
}
