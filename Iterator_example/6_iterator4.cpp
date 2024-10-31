#include <iostream>

template<typename T> struct Node
{
    T     data;
    Node* next;

    Node(const T& d, Node* n) : data(d), next(n) {}
};

//-------------------------------------------------------------
// ��Ģ 1. ��� �ݺ��ڴ� �Ʒ� �������̽��� �����ؾ� �Ѵ�.
template<typename T> struct IIterator
{
    virtual T& next() = 0;
    virtual bool hasNext() = 0;
    virtual ~IIterator() {}
};
// ��Ģ 2. ��� �÷����� �Ʒ� �������̽��� �����ؾ� �Ѵ�.
template<typename T> class ICollection
{
public:
    virtual IIterator<T>* iterator() = 0;
    virtual ~ICollection() {}
};
//-------------------------------------------------------------
// Java ��Ÿ�Ϸ� ���� �̱۸���Ʈ �ݺ���
// �ݺ����� �ٽ� : 1��° ��Ҹ� ����Ű�ٰ� ��ӵ� ������� �̵�
template<typename T> class slist_iterator : public IIterator<T>
{
    Node<T>* current;
public:
    slist_iterator(Node<T>* p = 0) : current(p) {}

    T& next() override
    {
        T& temp = current->data;
        current = current->next;
        return temp;
    }

    bool hasNext() override
    {
        return current != 0;
    }
};
//-------------------------------------------------------------
// ��� �÷����� �ݺ��ڸ� ���� �� �־�� �Ѵ�.
template<typename T> struct slist : public ICollection<T>
{
    Node<T>* head = 0;
public:
    void push_front(const T& a) { head = new Node<T>(a, head); }

    IIterator<T>* iterator() override
    {
        // slist_iterator ��ü�� list ù��° ��� �ּҷ� �ʱ�ȭ�ؼ� ��ȯ�ϸ� �ȴ�.
        return new slist_iterator<T>(head);
    }
};

int main()
{
    slist<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    s.push_front(40);

    auto it = s.iterator(); // auto�� IIterator<int>* �� �ȴ�.

    while (it->hasNext())
    {
        std::cout << it->next() << std::endl;
    }
}


// �� ����� ��κ��� ��ü������(C#, Java, Python, Swift ��)�� ����ϴ� ���
// 
// C++ �������� �� ��Ŀ� ���ؼ� �����ϴ� ������

// #1. s.iterator() ��ȯ�ϴ� �ݺ��ڴ� "new" �� ����� �˴ϴ�.
//	   delete �� �ʿ����� ������� ?
// 
// #2. �������� �̵��ϴ� next()/hasNext()�� �����Լ� �Դϴ�.
//     �����Լ��� ȣ���� ������尡 �ֽ��ϴ�.
//     next() �� �����ȿ��� ��õ ~ �������� ȣ��ɼ� �ֽ��ϴ�.
// 
// #3. �迭�� collection �Դϴ�.
//     C++���� �迭�� �����Ҷ��� "������" ����մϴ�.
//     p�� �������϶� "p->next()" �Ҽ� �����ϴ�.
//		�����ʹ� ++p �� �̵�
//     "��� �÷����� ������ �������" ��� ��Ģ ����