#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <cassert>    // For Test
#include <random>     // For Test
#include <functional> // For Test

template <typename T>
class Vector
{
public:
    // constructors
    Vector() = default;
    Vector(std::initializer_list<T> l);
    explicit Vector(size_t count);
    Vector(Vector<T> &&rhs);
    Vector(const Vector<T> &rhs);
    Vector<T> &operator=(const Vector<T> &rhs);
    Vector<T> &operator=(Vector<T> &&rhs);
    ~Vector();

    bool operator==(const Vector<T> &rhs) const;
    bool operator!=(const Vector<T> &rhs) const;

    T &operator[](size_t pos);
    const T &operator[](size_t pos) const;

    void Resize(size_t count);

    void PushBack(const T &val);
    void PushBack(T &&val);
    void PopBack();

    size_t Find(const T &val) const;
    size_t Count(const T &val) const;

    Vector<T> Concatenate(const Vector<T> &other) const;
    Vector<T> operator+(const Vector<T> &other) const;
    Vector<T> Repeat(size_t times) const;
    Vector<T> operator*(size_t times) const;

    Vector<T> Slice(size_t start, size_t stop) const;
    Vector<T> Split(size_t pos);
    void Unique();

    Vector<T> &Reverse();
    Vector<T> &Rotate(size_t step = 1);

    size_t Size() const { return size_; }

private:
    size_t size_ = 0;
    size_t capacity_ = 0;
    T *elems_ = nullptr;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Vector<T> &v)
{
    if (v.Size() == 0)
        return os << "[]";
    os << '[' << v[0];
    for (size_t i = 1; i < v.Size(); i++)
    {
        os << ", " << v[i];
    }
    return os << ']';
}

void Test1();  // Sample1
void Test2();  // Find, Count
void Test3();  // Reverse, Rotate
void Test4();  // Concatenate, opeartor+, Repeat, operator*
void Test5();  // Slice, Split, Unique
void Test6();  // All
void Test7();  // Find, Count
void Test8();  // Reverse, Rotate
void Test9();  // Concatenate, opeartor+, Repeat, operator*
void Test10(); // Slice, Split, Unique
void Test11(); // All

int main()
{
    int id;
    std::cin >> id;
    void (*f[])() = {
        Test1, Test2, Test3, Test4, Test5,
        Test6, Test7, Test8, Test9, Test10,
        Test11};
    f[id - 1]();
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> l)
{
    size_ = l.size();
    capacity_ = size_;
    elems_ = new T[capacity_];

    int i = 0;
    for (const T &v : l)
    {
        elems_[i] = v;
        ++i;
    }
}

template <typename T>
Vector<T>::Vector(size_t count)
{
    size_ = count;
    capacity_ = size_;
    elems_ = new T[capacity_]{};
}

template <typename T>
Vector<T>::Vector(const Vector<T> &rhs)
{
    size_ = rhs.size_;
    capacity_ = size_;
    elems_ = new T[capacity_];

    for (size_t i = 0; i < size_; i++)
    {
        elems_[i] = rhs.elems_[i];
    }
}

template <typename T>
Vector<T>::Vector(Vector<T> &&rhs)
{
    elems_ = rhs.elems_;
    size_ = rhs.size_;
    capacity_ = rhs.capacity_;

    rhs.size_ = 0;
    rhs.capacity_ = 0;
    rhs.elems_ = nullptr;
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] elems_;
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    Resize(rhs.size_);
    for (size_t i = 0; i < size_; i++)
    {
        elems_[i] = rhs.elems_[i];
    }
    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> &&rhs)
{
    delete[] elems_;

    capacity_ = rhs.capacity_;
    size_ = rhs.size_;
    elems_ = rhs.elems_;

    rhs.capacity_ = 0;
    rhs.size_ = 0;
    rhs.elems_ = nullptr;

    return *this;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T> &rhs) const
{
    if (this == &rhs)
    {
        return true;
    }
    if (size_ != rhs.size_)
    {
        return false;
    }
    for (size_t i = 0; i < size_; i++)
    {
        if (elems_[i] != rhs.elems_[i])
        {
            return false;
        }
    }
    return true;
}

template <typename T>
bool Vector<T>::operator!=(const Vector<T> &rhs) const
{
    return !(*this == rhs);
}

template <typename T>
void Vector<T>::Resize(size_t count)
{
    if (count <= capacity_)
    {
        for (size_t i = size_; i < count; i++)
        {
            elems_[i] = T{};
        }
        size_ = count;
        return;
    }

    capacity_ = std::max(count, 2 * (capacity_ + 1));

    T *newElems = new T[capacity_]{};
    for (size_t i = 0; i < size_; i++)
    {
        newElems[i] = elems_[i];
    }
    delete[] elems_;
    elems_ = newElems;
    size_ = count;
}

template <typename T>
void Vector<T>::PushBack(const T &val)
{
    Resize(Size() + 1);
    operator[](Size() - 1) = val;
}

template <typename T>
void Vector<T>::PushBack(T &&val)
{
    Resize(Size() + 1);
    operator[](Size() - 1) = std::move(val);
}

template <typename T>
void Vector<T>::PopBack()
{
    Resize(size_ - 1);
}

template <typename T>
T &Vector<T>::operator[](size_t pos)
{
    return elems_[pos];
}

template <typename T>
const T &Vector<T>::operator[](size_t pos) const
{
    return elems_[pos];
}

namespace Feis
{ /* HIDDEN */
}

void Test1()
{
    // Find, Count
    {
        Vector<int> a = {3, 9, 1, 7, 5, 6, 3};
        std::cout << a.Find(3) << std::endl;
        std::cout << a.Find(4) << std::endl;
        std::cout << a.Find(5) << std::endl;

        std::cout << a.Count(3) << std::endl;
        std::cout << a.Count(4) << std::endl;
        std::cout << a.Count(5) << std::endl;
    }

    // Reverse, Rotate
    {
        Vector<int> a = {3, 9, 1, 7, 5, 6, 3};

        std::cout << a << std::endl;
        std::cout << a.Reverse() << std::endl;
        std::cout << a << std::endl;

        std::cout << a.Rotate() << std::endl;
        std::cout << a << std::endl;

        std::cout << a.Rotate(3) << std::endl;
        std::cout << a << std::endl;
    }

    // Concatenate, operator+, Repeat, operator*
    {
        Vector<int> a = {3, 9, 1, 7};
        Vector<int> b = {4, 6, 5};

        std::cout << a << std::endl;
        std::cout << b << std::endl;

        std::cout << a.Concatenate(b) << std::endl;

        std::cout << a << std::endl;
        std::cout << b << std::endl;

        std::cout << (a + b) << std::endl;

        std::cout << a << std::endl;
        std::cout << b << std::endl;

        std::cout << a.Repeat(5) << std::endl;
        std::cout << a << std::endl;

        std::cout << (a * 5) << std::endl;
        std::cout << a << std::endl;
    }

    // Slice, Split, Unique
    {
        Vector<int> a = {3, 9, 1, 7};

        std::cout << a << std::endl;
        std::cout << a.Slice(1, 3) << std::endl;
        std::cout << a << std::endl;
        std::cout << a.Slice(3, 1) << std::endl;
        std::cout << a << std::endl;
        std::cout << a.Slice(0, 10) << std::endl;
        std::cout << a << std::endl;
        std::cout << a.Slice(6, 10) << std::endl;
        std::cout << a << std::endl;

        std::cout << a.Split(2) << std::endl;
        std::cout << a << std::endl;

        Vector<int> b = {5, 3, 3, 5, 2, 8, 7, 3, 9, 5};
        std::cout << b << std::endl;
        b.Unique();
        std::cout << b << std::endl;
    }
}

void Test2()
{ /* HIDDEN */
}
void Test3()
{ /* HIDDEN */
}
void Test4()
{ /* HIDDEN */
}
void Test5()
{ /* HIDDEN */
}
void Test6()
{ /* HIDDEN */
}
void Test7()
{ /* HIDDEN */
}
void Test8()
{ /* HIDDEN */
}
void Test9()
{ /* HIDDEN */
}
void Test10()
{ /* HIDDEN */
}
void Test11()
{ /* HIDDEN */
}

// [YOUR CODE WILL BE PLACED HERE]

using namespace std;
#include <algorithm>
template <typename T>
size_t Vector<T>::Find(const T &val) const
{
    for (int i = 0; i < size_; i++)
    {
        if (elems_[i] == val)
        {
            return i;
        }
    }
    return size_;
}

template <typename T>
size_t Vector<T>::Count(const T &val) const
{
    size_t count = 0;
    for (int i = 0; i < size_; i++)
    {
        if (elems_[i] == val)
        {
            count++;
        }
    }
    return count;
}

template <typename T>
Vector<T> &Vector<T>::Reverse()
{
    for (int i = 0; i < size_ / 2; i++)
    {
        swap(elems_[i], elems_[size_ - 1 - i]);
    }
    return *this;
}

template <typename T>
Vector<T> &Vector<T>::Rotate(size_t step)
{
    if (size_ > 1)
    {
        step = step % size_;
        Vector<T> temp(0);
        for (int i = step; i > 0; i--)
        {
            temp.PushBack(elems_[size_ - i]);
        }
        Resize(size_ - step);
        *this = temp.Concatenate(*this);
    }
    return *this;
}

template <typename T>
Vector<T> Vector<T>::Concatenate(const Vector<T> &other) const
{
    Vector<T> ans(size_ + other.size_);
    for (int i = 0; i < size_; i++)
    {
        ans.elems_[i] = elems_[i];
    }
    for (int i = size_; i < size_ + other.size_; i++)
    {
        ans.elems_[i] = other.elems_[i - size_];
    }
    return ans;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &other) const
{
    return Concatenate(other);
}

template <typename T>
Vector<T> Vector<T>::Repeat(size_t times) const
{
    Vector<T> ans(size_ * times);
    if (size_ == 0)
    {
        return ans;
    }
    for (int i = 0; i < times * size_; i++)
    {
        ans[i] = elems_[i % size_];
    }
    return ans;
}

template <typename T>
Vector<T> Vector<T>::operator*(size_t times) const
{
    return Repeat(times);
}

template <typename T>
Vector<T> Vector<T>::Slice(size_t start, size_t stop) const
{
    if (start >= stop)
    {
        Vector<T> ans{};
        return ans;
    }
    else
    {
        Vector<T> ans;
        for (int i = start; i < stop; i++)
        {
            if (i < size_)
            {
                ans.PushBack(elems_[i]);
            }
        }
        return ans;
    }
}

template <typename T>
Vector<T> Vector<T>::Split(size_t pos)
{
    Vector<T> ans;
    if (pos >= size_)
    {
        return ans;
    }
    else
    {
        for (int i = pos; i < size_; i++)
        {
            ans.PushBack(elems_[i]);
        }
        Resize(pos);
    }
    return ans;
}

template <typename T>
void Vector<T>::Unique()
{
    if (size_ > 0)
    {
        Vector<T> ans;
        ans.PushBack(elems_[0]);
        for (int i = 0; i < size_; i++)
        {
            if (ans.Find(elems_[i]) == ans.size_)
            {
                ans.PushBack(elems_[i]);
            }
        }
        Resize(ans.size_);
        for (int i = 0; i < ans.size_; i++)
        {
            elems_[i] = ans.elems_[i];
        }
    }
}
