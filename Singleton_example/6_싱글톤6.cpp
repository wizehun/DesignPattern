#include <iostream>
#include <mutex>

// CRTP : Curiously Recurring Template Pattern
// => ��� Ŭ�������� �̷��� ������� �Ļ� Ŭ���� �̸���
//    ����Ҽ� �ְ� �ϴ� ����

// => ���� : �Ļ� Ŭ���� ���鶧 �ڽ��� �̸���
//			��� Ŭ������ ���ø� ���ڷ� ����

// ����.. �ʹ��� �����ϴ� ���
// C++20�� Ranges ��� ǥ�� ���̺귯���� �� ����� �ۼ���. 


template<typename T>
class Singleton
{
protected:
    Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static T* sinstance;
    static std::mutex mtx;
public:

    static T& get_instance()
    {
        std::lock_guard<std::mutex> g(mtx);

        if (sinstance == nullptr)
            sinstance = new T;

        return *sinstance;
    }
};

template<typename T> T* Singleton<T>::sinstance = nullptr;
template<typename T> std::mutex Singleton<T>::mtx;

// Mouse Ŭ������ ��ó�� ���� ����� �̱������� �ϰ� �ʹ�.
class Mouse : public Singleton< Mouse >
{
};

int main()
{
    Mouse& c1 = Mouse::get_instance();
}





