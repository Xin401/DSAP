#include <initializer_list>
#include <iostream>
#include <cassert>    // For Test
#include <random>     // For Test
#include <functional> // For Test

template <typename T>
struct ListNode
{
    ListNode(T val) : val{std::move(val)}, next{nullptr} {}
    T val;
    ListNode<T> *next;
};

template <typename T>
class SinglyLinkedList;

template <typename T>
class SinglyLinkedListConstIterator
{
    friend class SinglyLinkedList<T>;

public:
    SinglyLinkedListConstIterator(ListNode<T> *ptr) : ptr_{ptr}
    {
    }
    bool operator==(const SinglyLinkedListConstIterator<T> &rhs) const
    {
        return ptr_ == rhs.ptr_;
    }
    bool operator!=(const SinglyLinkedListConstIterator<T> &rhs) const
    {
        return ptr_ != rhs.ptr_;
    }
    SinglyLinkedListConstIterator<T> &operator++()
    {
        ptr_ = ptr_->next;
        return *this;
    }
    SinglyLinkedListConstIterator<T> operator++(int)
    {
        SinglyLinkedListConstIterator<T> prev = *this;
        ptr_ = ptr_->next;
        return prev;
    }
    const T &operator*() const
    {
        return ptr_->val;
    }
    const T *operator->() const
    {
        return ptr_;
    }

private:
    ListNode<T> *ptr_;
};

template <typename T>
class SinglyLinkedListIterator
{
    friend class SinglyLinkedList<T>;

public:
    SinglyLinkedListIterator(ListNode<T> *ptr) : ptr_{ptr}
    {
    }
    bool operator==(const SinglyLinkedListIterator<T> &rhs) const
    {
        return ptr_ == rhs.ptr_;
    }
    bool operator!=(const SinglyLinkedListIterator<T> &rhs) const
    {
        return ptr_ != rhs.ptr_;
    }
    SinglyLinkedListIterator<T> &operator++()
    {
        ptr_ = ptr_->next;
        return *this;
    }
    SinglyLinkedListIterator<T> operator++(int)
    {
        SinglyLinkedListIterator<T> prev = *this;
        ptr_ = ptr_->next;
        return prev;
    }
    T &operator*()
    {
        return ptr_->val;
    }
    T *operator->()
    {
        return ptr_;
    }

private:
    ListNode<T> *ptr_;
};

template <typename Iterator>
void Advance(Iterator &iter, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        ++iter;
    }
}

template <typename T>
class SinglyLinkedList
{
public:
    SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList<T> &);
    SinglyLinkedList &operator=(const SinglyLinkedList<T> &);
    SinglyLinkedList(std::initializer_list<T>);
    ~SinglyLinkedList();

    bool Empty() const;
    void PushFront(const T &);
    void PopFront();

    void Clear();
    void Swap(SinglyLinkedList<T> &other);

    void Remove(const T &val);
    void Reverse();
    void Sort();

    void Erase(size_t pos);

    void EraseAfter(SinglyLinkedListIterator<T> pos);

    void Insert(size_t pos, const T &val);
    void Insert(size_t pos, const SinglyLinkedList<T> &other);

    void InsertAfter(SinglyLinkedListIterator<T> pos, const T &);
    void InsertAfter(SinglyLinkedListIterator<T> pos, const SinglyLinkedList<T> &);

    SinglyLinkedListIterator<T> Begin();
    SinglyLinkedListConstIterator<T> Begin() const;
    SinglyLinkedListIterator<T> End();
    SinglyLinkedListConstIterator<T> End() const;

private:
    ListNode<T> *head_;
};

template <typename T>
std::ostream &operator<<(std::ostream &, const SinglyLinkedList<T> &);

void Test1();  // Sample1
void Test2();  // Swap, Clear
void Test3();  // Remove
void Test4();  // Reverse
void Test5();  // Sort
void Test6();  // Erase(size_t)
void Test7();  // EraseAfter(iterator)
void Test8();  // Insert(size_t, T)
void Test9();  // Insert(size_t, SinglyLinkedList<T>)
void Test10(); // InsertAfter(iterator, T)
void Test11(); // InsertAfter(iterator, SinglyLinkedList<T>)
void Test12(); // All
void Test13(); // Sort (Same as Test5)

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int id;
    std::cin >> id;
    void (*f[])() = {
        Test1, Test2, Test3, Test4, Test5, Test6,
        Test7, Test8, Test9, Test10, Test11, Test12,
        Test13};
    f[id - 1]();
}

void Test1()
{
    // Swap, Clear
    {
        SinglyLinkedList<int> l1 = {0, 1, 2, 3, 4, 5};
        SinglyLinkedList<int> l2 = {10, 11, 12};

        std::cout << "01) " << l1 << std::endl;
        std::cout << "02) " << l2 << std::endl;

        l1.Swap(l2);
        std::cout << "03) " << l1 << std::endl;
        std::cout << "04) " << l2 << std::endl;

        l1.Clear();
        std::cout << "05) " << l1 << std::endl;
    }

    // Remove
    {
        SinglyLinkedList<int> l = {3, 9, 1, 7, 5, 3, 9};

        l.Remove(3);
        std::cout << "06) " << l << std::endl;

        l.Remove(4);
        std::cout << "07) " << l << std::endl;
    }

    // Reverse
    {
        SinglyLinkedList<int> l = {0, 1, 3, 4, 5};
        l.Reverse();
        std::cout << "08) " << l << std::endl;

        l.Reverse();
        std::cout << "09) " << l << std::endl;
    }

    // Sort
    {
        SinglyLinkedList<int> l = {3, 5, 1, 4, 2};

        l.Sort();
        std::cout << "10) " << l << std::endl;
    }

    // Erase (size_t)
    {
        SinglyLinkedList<int> l = {0, 1, 2, 3, 4};

        l.Erase(0);
        std::cout << "11) " << l << std::endl;

        l.Erase(3);
        std::cout << "12) " << l << std::endl;

        l.Erase(1);
        std::cout << "13) " << l << std::endl;
    }

    // EraseAfter (iterator)
    {
        SinglyLinkedList<int> l = {0, 1, 2, 3, 4};

        l.PopFront();
        std::cout << "14) " << l << std::endl;

        SinglyLinkedListIterator<int> p1 = l.Begin();
        Advance(p1, 2);

        l.EraseAfter(p1);
        std::cout << "15) " << l << std::endl;

        SinglyLinkedListIterator<int> p2 = l.Begin();

        l.EraseAfter(p2);
        std::cout << "16) " << l << std::endl;
    }

    // Insert(size_t pos)
    {
        SinglyLinkedList<int> l1 = {0, 1, 2, 3, 4};
        SinglyLinkedList<int> l2 = {10, 11, 12};

        l1.Insert(5, 5);
        std::cout << "17) " << l1 << std::endl;

        l1.Insert(0, 6);
        std::cout << "18) " << l1 << std::endl;

        l1.Insert(1, 7);
        std::cout << "19) " << l1 << std::endl;

        l1.Insert(0, l2);
        std::cout << "20) " << l1 << std::endl;
        std::cout << "21) " << l2 << std::endl;
    }

    // InsertAfter(iterator pos)
    {
        SinglyLinkedList<int> l1 = {0, 1, 2, 3, 4};
        SinglyLinkedList<int> l2 = {10, 11, 12};

        SinglyLinkedListIterator<int> p1 = l1.Begin();
        Advance(p1, 4);

        l1.InsertAfter(p1, 5);
        std::cout << "22) " << l1 << std::endl;

        l1.PushFront(6);
        std::cout << "23) " << l1 << std::endl;

        l1.InsertAfter(l1.Begin(), 7);
        std::cout << "24) " << l1 << std::endl;

        SinglyLinkedListIterator<int> p2 = l1.Begin();
        Advance(p2, 1);

        l1.InsertAfter(p2, l2);
        std::cout << "25) " << l1 << std::endl;
        std::cout << "26) " << l2 << std::endl;
    }
}

namespace Feis
{
}

void Test2() {}
void Test3() {}
void Test4() {}
void Test5() {}
void Test6() {}
void Test7() {}
void Test8() {}
void Test9() {}
void Test10() {}
void Test11() {}
void Test12() {}
void Test13() {}

template <typename T>
std::ostream &operator<<(std::ostream &os, const SinglyLinkedList<T> &l)
{
    os << '[';
    for (SinglyLinkedListConstIterator<T> p = l.Begin(); p != l.End(); ++p)
    {
        if (p != l.Begin())
        {
            os << ", ";
        }
        os << *p;
    }
    os << ']';
    return os;
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head_{nullptr}
{
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T> &other) : head_{nullptr}
{
    ListNode<T> temp(T{});
    ListNode<T> *insertAt = &temp;
    for (SinglyLinkedListConstIterator<T> p = other.Begin(); p != other.End(); ++p)
    {
        insertAt->next = new ListNode<T>(*p);
        insertAt = insertAt->next;
    }
    head_ = temp.next;
}

template <typename T>
SinglyLinkedList<T> &SinglyLinkedList<T>::operator=(const SinglyLinkedList<T> &other)
{
    if (this == &other)
    {
        return *this;
    }
    SinglyLinkedList<T> temp = other;
    std::swap(head_, other.head_);
    return *this;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    while (!Empty())
    {
        PopFront();
    }
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(std::initializer_list<T> l)
{
    ListNode<T> temp(T{});
    ListNode<T> *prev = &temp;
    for (const auto &v : l)
    {
        prev->next = new ListNode<T>(v);
        prev = prev->next;
    }
    head_ = temp.next;
}

template <typename T>
bool SinglyLinkedList<T>::Empty() const
{
    return head_ == nullptr;
}

template <typename T>
void SinglyLinkedList<T>::PushFront(const T &val)
{
    ListNode<T> *temp = head_;
    head_ = new ListNode<T>(val);
    head_->next = temp;
}

template <typename T>
void SinglyLinkedList<T>::PopFront()
{
    ListNode<T> *temp = head_->next;
    delete head_;
    head_ = temp;
}

template <typename T>
SinglyLinkedListConstIterator<T> SinglyLinkedList<T>::Begin() const
{
    return head_;
}

template <typename T>
SinglyLinkedListIterator<T> SinglyLinkedList<T>::Begin()
{
    return head_;
}

template <typename T>
SinglyLinkedListConstIterator<T> SinglyLinkedList<T>::End() const
{
    return nullptr;
}

template <typename T>
SinglyLinkedListIterator<T> SinglyLinkedList<T>::End()
{
    return nullptr;
}

// [YOUR CODE WILL BE PLACED HERE]

template <typename T>
void SinglyLinkedList<T>::Clear()
{
    head_ = nullptr;
}

template <typename T>
void SinglyLinkedList<T>::Swap(SinglyLinkedList<T> &other)
{
    ListNode<T> *temp = head_;
    head_ = other.head_;
    other.head_ = temp;
}
template <typename T>
void SinglyLinkedList<T>::Remove(const T &val)
{
    if (head_ != nullptr)
    {
        while (head_->val == val)
        {
            head_ = head_->next;
        }
        if (head_ != nullptr)
        {
            ListNode<T> *tempI = head_;
            ListNode<T> *tempII = head_;
            tempI = tempI->next;
            while (tempI != nullptr)
            {
                if (tempI->val == val)
                {
                    tempII->next = tempI->next;
                    tempI = tempI->next;
                }
                else
                {
                    tempI = tempI->next;
                    tempII = tempII->next;
                }
            }
        }
    }
}

template <typename T>
void SinglyLinkedList<T>::Reverse()
{
    if (head_ == nullptr || head_->next == nullptr)
    {
        return;
    }
    ListNode<T> *first = head_->next;
    ListNode<T> *second = head_;
    second->next = nullptr;
    while (first != nullptr)
    {
        ListNode<T> *temp = first->next;
        first->next = second;
        second = first;
        first = temp;
    }
    head_ = second;
}

template <typename T>
void SinglyLinkedList<T>::Sort()
{
    MergeSort(&head_);
}

template <typename T>
void MergeSort(ListNode<T> **ref)
{
    ListNode<T> *head = *ref;
    ListNode<T> *a;
    ListNode<T> *b;
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }
    FrontBackSplit(head, &a, &b);
    MergeSort(&a);
    MergeSort(&b);
    *ref = SortedMerge(a, b);
}

template <typename T>
ListNode<T> *SortedMerge(ListNode<T> *a, ListNode<T> *b)
{
    ListNode<T> *result = nullptr;
    if (a == nullptr)
    {
        return b;
    }
    if (b == nullptr)
    {
        return a;
    }
    if (a->val <= b->val)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return result;
}

template <typename T>
void FrontBackSplit(ListNode<T> *source, ListNode<T> **fornt_ref, ListNode<T> **back_ref)
{
    ListNode<T> *fast;
    ListNode<T> *slow;
    slow = source;
    fast = source->next;
    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    *fornt_ref = source;
    *back_ref = slow->next;
    slow->next = nullptr;
}

template <typename T>
void SinglyLinkedList<T>::Erase(size_t pos)
{
    if (pos == 0)
    {
        head_ = head_->next;
    }
    else
    {
        ListNode<T> *temp = head_;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp != nullptr)
            {
                temp = temp->next;
            }
        }
        if (temp != nullptr && temp->next != nullptr)
        {
            temp->next = temp->next->next;
        }
    }
}

template <typename T>
void SinglyLinkedList<T>::EraseAfter(SinglyLinkedListIterator<T> pos)
{
    ListNode<T> *temp = pos.ptr_;
    if (temp != nullptr)
    {
        if (temp->next != nullptr)
        {
            temp->next = temp->next->next;
        }
    }
}

template <typename T>
void SinglyLinkedList<T>::Insert(size_t pos, const T &val)
{
    if (pos == 0)
    {
        ListNode<T> *temp = new ListNode(val);
        temp->next = head_;
        head_ = temp;
    }
    else
    {
        bool flag = true;
        ListNode<T> *temp = head_;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp != nullptr)
            {
                temp = temp->next;
            }
            else
            {
                flag = false;
            }
        }
        if (flag && temp != nullptr)
        {
            ListNode<T> *tempII = new ListNode(val);
            tempII->next = temp->next;
            temp->next = tempII;
        }
    }
}

template <typename T>
void SinglyLinkedList<T>::Insert(size_t pos, const SinglyLinkedList<T> &other)
{
    if (other.head_ == nullptr)
    {
        return;
    }
    ListNode<T> *current = new ListNode(other.head_->val);
    ListNode<T> *builder = current;
    ListNode<T> *temp = other.head_->next;
    while (temp != nullptr)
    {
        builder->next = new ListNode(temp->val);
        builder = builder->next;
        temp = temp->next;
    }
    if (pos == 0)
    {
        if (head_ == nullptr)
        {
            head_ = current;
            return;
        }
        builder->next = head_;
        head_ = current;
    }
    else
    {
        bool flag = true;
        ListNode<T> *temp = head_;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp != nullptr)
            {
                temp = temp->next;
            }
            else
            {
                flag = false;
            }
        }
        if (flag && temp != nullptr)
        {
            builder->next = temp->next;
            temp->next = current;
        }
    }
}

template <typename T>
void SinglyLinkedList<T>::InsertAfter(SinglyLinkedListIterator<T> pos, const T &val)
{
    if (pos.ptr_ != nullptr)
    {
        ListNode<T> *temp = pos.ptr_->next;
        ListNode<T> *insert = new ListNode(val);
        pos.ptr_->next = insert;
        insert->next = temp;
    }
}

template <typename T>
void SinglyLinkedList<T>::InsertAfter(SinglyLinkedListIterator<T> pos, const SinglyLinkedList<T> &other)
{
    if (head_ == nullptr || other.head_ == nullptr)
    {
        return;
    }
    ListNode<T> *head = new ListNode(other.head_->val);
    ListNode<T> *temp = other.head_->next;
    ListNode<T> *builder = head;
    while (temp != nullptr)
    {
        builder->next = new ListNode(temp->val);
        builder = builder->next;
        temp = temp->next;
    }
    if (pos.ptr_ != nullptr)
    {
        builder->next = pos.ptr_->next;
        pos.ptr_->next = head;
    }
}
