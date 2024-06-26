#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <cassert>    // For Test
#include <random>     // For Test
#include <functional> // For Test

// Vector 類別模板宣告與定義

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

    bool operator==(const Vector<T> &rhs);
    bool operator!=(const Vector<T> &rhs);

    T &operator[](size_t pos);
    const T &operator[](size_t pos) const;
    T &At(size_t pos);
    const T &At(size_t pos) const;

    T &Front();
    const T &Front() const;
    T &Back();
    const T &Back() const;

    void Resize(size_t count);

    void PushBack(const T &val);
    void PushBack(T &&val);
    void PopBack();

    void PushFront(const T &val);
    void PushFront(T &&val);
    void PopFront();

    void Insert(size_t pos, const T &val);
    void Insert(size_t pos, T &&val);
    void Erase(size_t pos);

    void Fill(const T &v);
    void Assign(size_t count, const T &val);
    void Clear();
    void Remove(const T &val);
    void Swap(Vector<T> &other);

    size_t Size() const { return size_; }

    size_t Capacity() const { return capacity_; }

private:
    size_t size_ = 0;
    size_t capacity_ = 0;
    T *elems_ = nullptr;
};

// Vector 類別模板的相關函式定義

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
bool Vector<T>::operator==(const Vector<T> &rhs)
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
bool Vector<T>::operator!=(const Vector<T> &rhs)
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
    Resize(size_ + 1);
    elems_[size_ - 1] = val;
}

template <typename T>
void Vector<T>::PushBack(T &&val)
{
    Resize(size_ + 1);
    elems_[size_ - 1] = std::move(val);
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

template <typename T>
T &Vector<T>::At(size_t pos)
{
    if (pos >= size_)
    {
        throw std::out_of_range{std::to_string(pos) + " >= " + std::to_string(size_)};
    }
    return elems_[pos];
}

template <typename T>
const T &Vector<T>::At(size_t pos) const
{
    return const_cast<Vector *>(this)->At(pos);
}

template <typename T>
T &Vector<T>::Front()
{
    return elems_[0];
}

template <typename T>
const T &Vector<T>::Front() const
{

    return elems_[0];
}

template <typename T>
void Vector<T>::PopFront()
{
    for (size_t i = 0; i + 1 < size_; i++)
    {
        elems_[i] = elems_[i + 1];
    }
    Resize(size_ - 1);
}

template <typename T>
T &Vector<T>::Back()
{
    return elems_[size_ - 1];
}

template <typename T>
const T &Vector<T>::Back() const
{
    return elems_[size_ - 1];
}

template <typename T>
void Vector<T>::PushFront(const T &val)
{
    Resize(size_ + 1);
    for (size_t i = size_ - 1; i > 0; i--)
    {
        elems_[i] = elems_[i - 1];
    }
    elems_[0] = val;
}

template <typename T>
void Vector<T>::PushFront(T &&val)
{
    Resize(size_ + 1);
    for (size_t i = size_ - 1; i > 0; i--)
    {
        elems_[i] = elems_[i - 1];
    }
    elems_[0] = std::move(val);
}

template <typename T>
void Vector<T>::Insert(size_t pos, const T &val)
{
    Resize(size_ + 1);
    for (size_t i = size_ - 1; i > pos; i--)
    {
        elems_[i] = elems_[i - 1];
    }
    elems_[pos] = val;
}

template <typename T>
void Vector<T>::Insert(size_t pos, T &&val)
{
    Resize(size_ + 1);
    for (size_t i = size_ - 1; i > pos; i--)
    {
        elems_[i] = std::move(elems_[i - 1]);
    }
    elems_[pos] = std::move(val);
}

template <typename T>
void Vector<T>::Erase(size_t pos)
{
    for (size_t i = pos; i + 1 < size_; i++)
    {
        elems_[i] = std::move(elems_[i + 1]);
    }
    Resize(size_ - 1);
}

template <typename T>
void Vector<T>::Fill(const T &v)
{
    for (size_t i = 0; i < size_; i++)
    {
        elems_[i] = v;
    }
}

template <typename T>
void Vector<T>::Clear()
{
    size_ = 0;
}

template <typename T>
void Vector<T>::Remove(const T &val)
{
    size_t j = 0;
    for (size_t i = 0; i < size_; i++)
    {
        if (elems_[i] != val)
        {
            elems_[j] = std::move(elems_[i]);
            j++;
        }
    }
    if (j != size_)
    {
        Resize(j);
    }
}

template <typename T>
void Vector<T>::Swap(Vector<T> &other)
{
    std::swap(*this, other);
}

template <typename T>
void Vector<T>::Assign(size_t count, const T &val)
{
    Resize(count);
    for (size_t i = 0; i < size_; i++)
    {
        elems_[i] = val;
    }
}

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

// NumericArray 類別模板宣告與定義

template <typename T>
class NumericArray;

template <typename T>
std::ostream &operator<<(std::ostream &os, const NumericArray<T> &a);

// 模板參數 T 的合理型態會支援：
// - 值初始化：歸零
// - 複製語意：複製建構與賦值
// - 同型態間的算術運算：+, -, * 與 / 運算
// - 同型態間的比較運算：==, !=, >, >=, <, <=
// 符合以上要求的可能型態有：int, double, ...
template <typename T>
class NumericArray
{
    friend std::ostream &operator<<<>(std::ostream &os, const NumericArray<T> &a);

public:
    NumericArray() = default;
    NumericArray(std::initializer_list<T> l) : repr_{l} {}
    NumericArray(size_t count, const T &val);

    T &operator[](size_t pos);
    const T &operator[](size_t pos) const;

    size_t Size() const;

    T &Front();
    const T &Front() const;

    T &Back();
    const T &Back() const;

    void Resize(size_t count);

    void PushBack(const T &val);
    void PushBack(T &&val);

    void PopBack();

    bool operator==(const NumericArray<T> &rhs);
    bool operator!=(const NumericArray<T> &rhs);

    // TODO
    T Max() const;

    // TODO
    T Min() const;

    // TODO
    T Median() const;

    // TODO
    T Average() const;

    // TODO
    T Sum() const;

    // TODO
    NumericArray<T> &Sort();

    // TODO
    void TrimZeroes();

private:
    Vector<T> repr_;
};

// TODO
template <typename T>
NumericArray<T> operator*(const NumericArray<T> &lhs, const T &rhs);

// TODO
template <typename T>
NumericArray<T> operator*(const T &lhs, const NumericArray<T> &rhs);

// TODO
template <typename T>
NumericArray<T> operator/(const NumericArray<T> &lhs, const T &rhs);

// 主函式定義

void Test1(); // Sample1
void Test2(); // operator*, operator/
void Test3(); // Max, Min
void Test4(); // Median, Sort
void Test5(); // Sum, Average
void Test6(); // TrimZeroes
void Test7(); // All

int main()
{
    int id;
    std::cin >> id;
    void (*f[])() = {Test1, Test2, Test3, Test4, Test5, Test6, Test7};
    f[id - 1]();
}

namespace Feis
{ /* HIDDEN */
}

void Test1()
{
    // Part 1. operator*, operator/
    {
        const NumericArray<int> a{0, 7, 3, 2, 9, 5, -3, 0};

        std::cout << "1.1) " << a << std::endl;
        std::cout << "1.2) " << (3 * a) << std::endl;
        std::cout << "1.3) " << (a * 4) << std::endl;

        const NumericArray<double> b{0, 7, 3, 2, 9, 5, -3, 0};
        std::cout << "1.4) " << b << std::endl;
        std::cout << "1.5) " << (0.5 * b) << std::endl;
        std::cout << "1.6) " << (b * 3.5) << std::endl;

        std::cout << "1.7) " << (a / 2) << std::endl;
        std::cout << "1.8) " << (b / 2.0) << std::endl;
    }

    // Part 2. Max, Min
    {
        const NumericArray<int> a{0, 7, 3, 2, 9, 5, -3, 0};
        std::cout << "2.1) " << a.Max() << std::endl;
        std::cout << "2.2) " << a.Min() << std::endl;
    }

    // Part 3: Median, Sort
    {
        NumericArray<int> a{0, 7, 3, 2, 9, 5, -3, 0};
        std::cout << "3.1) " << a.Median() << std::endl;
        std::cout << "3.2) " << a << std::endl;
        std::cout << "3.3) " << a.Sort() << std::endl;

        NumericArray<double> b{1, 0, 7, 3, 2, 9, 5, -3, 0};
        std::cout << "3.4) " << b.Median() << std::endl;
        std::cout << "3.5) " << b << std::endl;
        std::cout << "3.6) " << b.Sort() << std::endl;
    }

    // Part 4: Sum, Average
    {
        const NumericArray<int> a{0, 7, 3, 2, 9, 5, -3, 0};
        std::cout << "4.1) " << a.Sum() << std::endl;
        std::cout << "4.2) " << a << std::endl;
        std::cout << "4.3) " << a.Average() << std::endl;

        const NumericArray<double> b{0, 7, 3, 2, 9, 5, -3, 0};
        std::cout << "4.4) " << b.Sum() << std::endl;
        std::cout << "4.5) " << b << std::endl;
        std::cout << "4.6) " << b.Average() << std::endl;
    }

    // Part 5: TrimZeroes
    {
        NumericArray<int> a{0, 7, 3, 2, 9, 5, -3, 0};
        a.TrimZeroes();
        std::cout << "5.1) " << a << std::endl;

        NumericArray<double> b{1, 0, 7, 3, 2, 9, 5, -3, 0};
        b.TrimZeroes();
        std::cout << "5.2) " << b << std::endl;
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

// NumericArray 類別模板的相關函式定義

template <typename T>
std::ostream &operator<<(std::ostream &os, const NumericArray<T> &v)
{
    return os << v.repr_;
}

template <typename T>
NumericArray<T>::NumericArray(size_t count, const T &val) : repr_(count)
{
    for (size_t i = 0; i < repr_.Size(); ++i)
    {
        repr_[i] = val;
    }
}

template <typename T>
const T &NumericArray<T>::Front() const
{
    return repr_.Front();
}

template <typename T>
T &NumericArray<T>::Front()
{
    return repr_.Front();
}

template <typename T>
const T &NumericArray<T>::Back() const
{
    return repr_.Back();
}

template <typename T>
T &NumericArray<T>::Back()
{
    return repr_.Back();
}

template <typename T>
void NumericArray<T>::Resize(size_t count)
{
    repr_.Resize(count);
}

template <typename T>
void NumericArray<T>::PushBack(const T &val)
{
    repr_.PushBack(val);
}

template <typename T>
void NumericArray<T>::PushBack(T &&val)
{
    repr_.PushBack(std::move(val));
}

template <typename T>
void NumericArray<T>::PopBack()
{
    repr_.PopBack();
}

template <typename T>
T &NumericArray<T>::operator[](size_t pos)
{
    return repr_[pos];
}

template <typename T>
const T &NumericArray<T>::operator[](size_t pos) const
{
    return repr_[pos];
}

template <typename T>
size_t NumericArray<T>::Size() const
{
    return repr_.Size();
}

template <typename T>
bool NumericArray<T>::operator==(const NumericArray<T> &rhs)
{
    return repr_ == rhs.repr_;
}

template <typename T>
bool NumericArray<T>::operator!=(const NumericArray<T> &rhs)
{
    return repr_ != rhs.repr_;
}

// [YOUR CODE WILL BE PLACED HERE]

#include <algorithm>
#include <vector>
using namespace std;
template <typename T>
T NumericArray<T>::Max() const
{
    T ans = repr_[0];
    for (int i = 1; i < this->Size(); i++)
    {
        ans = max(repr_[i], ans);
    }
    return ans;
}

template <typename T>
T NumericArray<T>::Min() const
{
    T ans = repr_[0];
    for (int i = 1; i < this->Size(); i++)
    {
        ans = min(repr_[i], ans);
    }
    return ans;
}

template <typename T>
T NumericArray<T>::Median() const
{
    T ans = 0;
    vector<T> temp;
    for (int i = 0; i < Size(); i++)
    {
        temp.push_back(this->repr_[i]);
    }
    sort(temp.begin(), temp.end());
    if (Size() % 2 == 1)
    {
        ans = temp[Size() / 2];
    }
    else
    {
        ans = temp[(Size() / 2)];
    }
    return ans;
}
template <typename T>
T NumericArray<T>::Sum() const
{
    T ans = 0;
    for (int i = 0; i < Size(); i++)
    {
        ans += repr_[i];
    }
    return ans;
}

template <typename T>
T NumericArray<T>::Average() const
{
    return Sum() / static_cast<T>(Size());
}

template <typename T>
NumericArray<T> &NumericArray<T>::Sort()
{
    vector<T> temp;
    for (int i = 0; i < Size(); i++)
    {
        temp.push_back(this->repr_[i]);
    }
    sort(temp.begin(), temp.end());
    for (int i = 0; i < Size(); i++)
    {
        repr_[i] = temp[i];
    }
    return *this;
}

template <typename T>
void NumericArray<T>::TrimZeroes()
{
    while (repr_[0] == 0 && Size() != 0)
    {
        repr_.PopFront();
    }
    while (repr_[Size() - 1] == 0 && Size() != 0)
    {
        repr_.PopBack();
    }
}

template <typename T>
NumericArray<T> operator*(const NumericArray<T> &lhs, const T &rhs)
{
    NumericArray<T> ans{lhs};
    for (int i = 0; i < lhs.Size(); i++)
    {
        ans[i] *= rhs;
    }
    return ans;
}

template <typename T>
NumericArray<T> operator*(const T &lhs, const NumericArray<T> &rhs)
{
    NumericArray<T> ans{rhs};
    for (int i = 0; i < rhs.Size(); i++)
    {
        ans[i] *= lhs;
    }
    return ans;
}

template <typename T>
NumericArray<T> operator/(const NumericArray<T> &lhs, const T &rhs)
{
    NumericArray<T> ans{lhs};
    for (int i = 0; i < lhs.Size(); i++)
    {
        ans[i] /= rhs;
    }
    return ans;
}