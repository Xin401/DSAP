#include <vector>
#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <cassert>    // For Test
#include <random>     // For Test
#include <functional> // For Test

// 模板參數 T 的合理型態會支援：
// - 值初始化：歸零 (T{})
// - 複製語意：複製建構與賦值 (=)
// - 同型態間的比較運算：==, !=, >, >=, <, <=
// 符合以上要求的可能型態有：int, double, std::string, ...
template <typename T>
class ImmutableSet
{
public:
    ImmutableSet() = default;
    // TODO
    ImmutableSet(std::initializer_list<T> l);
    // TODO
    ImmutableSet(const std::vector<T> &values);

    size_t Size() const { return repr_.size(); }
    const std::vector<T> &Values() const { return repr_; }

    // TODO: check where the value is a member of this set
    bool Contains(const T &value) const;

    // TODO: check whether the two sets are disjoint or not
    bool IsDisjointWith(const ImmutableSet<T> &other) const;

private:
    std::vector<T> repr_;
};

// TODO: checks if the contents of lhs and rhs are equal
template <typename T>
bool operator==(const ImmutableSet<T> &lhs, const ImmutableSet<T> &rhs);

// TODO: checks if the contents of lhs and rhs are not equal
template <typename T>
bool operator!=(const ImmutableSet<T> &lhs, const ImmutableSet<T> &rhs);

// TODO: check whether every element in lhs is in rhs
template <typename T>
bool operator<=(const ImmutableSet<T> &lhs, const ImmutableSet<T> &rhs);

// TODO: check whether every element in rhs is in lhs
template <typename T>
bool operator>=(const ImmutableSet<T> &lhs, const ImmutableSet<T> &rhs);

// TODO: return a new set with elements common to lhs and rhs
template <typename T>
ImmutableSet<T> operator&(const ImmutableSet<T> &lhs, const ImmutableSet<T> &rhs);

// TODO: return a new set with elements from lhs and rhs
template <typename T>
ImmutableSet<T> operator|(const ImmutableSet<T> &lhs, const ImmutableSet<T> &rhs);

template <typename T>
std::ostream &operator<<(std::ostream &os, const ImmutableSet<T> &s)
{
    std::vector<T> output{s.Values()};
    std::sort(std::begin(output), std::end(output));

    os << '{';
    if (output.size() > 0)
    {
        os << output[0];
        for (size_t i = 1; i < output.size(); ++i)
        {
            os << ", " << output[i];
        }
    }
    os << '}';
    return os;
}

void Test1();  // Sample1
void Test2();  // constructors and Contains
void Test3();  // constructors, operator==, operator!=
void Test4();  // constructors, operator<=, operator>=
void Test5();  // constructors, operator&, operator|, IsDisjointWith
void Test6();  // All
void Test7();  // constructors and Contains
void Test8();  // constructors, operator==, operator!=
void Test9();  // constructors, operator<=, operator>=
void Test10(); // constructors, operator&, operator|, IsDisjointWith

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int id;
    std::cin >> id;
    void (*f[])() = {Test1, Test2, Test3, Test4, Test5, Test6, Test7, Test8, Test9, Test10};
    f[id - 1]();
}

namespace Feis
{ /* HIDDEN */
}

void Test1()
{
    // constructors and Contains
    {
        ImmutableSet<int> a = {5, 1, 3};
        ImmutableSet<int> b = std::vector<int>({3, 5, 1, 3});

        std::cout << "1.1)  " << a << std::endl;
        std::cout << "1.2)  " << b << std::endl;

        std::cout << "1.3)  " << std::boolalpha << a.Contains(1) << std::endl;
        std::cout << "1.4)  " << std::boolalpha << a.Contains(2) << std::endl;
        std::cout << "1.5)  " << std::boolalpha << a.Contains(3) << std::endl;
        std::cout << "1.6)  " << std::boolalpha << b.Contains(1) << std::endl;
        std::cout << "1.7)  " << std::boolalpha << b.Contains(2) << std::endl;
        std::cout << "1.8)  " << std::boolalpha << b.Contains(3) << std::endl;
    }

    // operator==, operator !=
    {
        ImmutableSet<int> a = {1, 3};
        ImmutableSet<int> b = {1, 3, 2};
        ImmutableSet<int> c = {3, 1};

        std::cout << "2.1)  " << std::boolalpha << (a == a) << std::endl;
        std::cout << "2.2)  " << std::boolalpha << (a == b) << std::endl;
        std::cout << "2.3)  " << std::boolalpha << (a == c) << std::endl;
        std::cout << "2.4)  " << std::boolalpha << (a != a) << std::endl;
        std::cout << "2.5)  " << std::boolalpha << (a != b) << std::endl;
        std::cout << "2.6)  " << std::boolalpha << (a != c) << std::endl;

        ImmutableSet<double> d = {1.5, 3.4};
        ImmutableSet<double> e = {1.5, 3.5, 2.5};
        ImmutableSet<double> f = {3.5, 1.5};

        std::cout << "2.7)  " << std::boolalpha << (d == e) << std::endl;
        std::cout << "2.8)  " << std::boolalpha << (d == f) << std::endl;
        std::cout << "2.9)  " << std::boolalpha << (d != e) << std::endl;
        std::cout << "2.10) " << std::boolalpha << (d != f) << std::endl;
    }

    // operator<=, operator>=
    {
        ImmutableSet<int> a = {1, 3};
        ImmutableSet<int> b = {1, 3, 2};
        ImmutableSet<int> c = {3, 2};

        std::cout << "3.1)  " << std::boolalpha << (a <= b) << std::endl;
        std::cout << "3.2)  " << std::boolalpha << (a >= b) << std::endl;
        std::cout << "3.3)  " << std::boolalpha << (a <= c) << std::endl;
        std::cout << "3.4)  " << std::boolalpha << (a >= c) << std::endl;
        std::cout << "3.5)  " << std::boolalpha << (b <= c) << std::endl;
        std::cout << "3.6)  " << std::boolalpha << (b >= c) << std::endl;

        ImmutableSet<double> d = {1.5, 3.5};
        ImmutableSet<double> e = {1.5, 3.5, 2.4};
        ImmutableSet<double> f = {3.5, 2.5};

        std::cout << "3.7)  " << std::boolalpha << (d <= e) << std::endl;
        std::cout << "3.8)  " << std::boolalpha << (d >= e) << std::endl;
        std::cout << "3.9)  " << std::boolalpha << (d <= f) << std::endl;
        std::cout << "3.10) " << std::boolalpha << (d >= f) << std::endl;
        std::cout << "3.11) " << std::boolalpha << (e <= f) << std::endl;
        std::cout << "3.12) " << std::boolalpha << (e >= f) << std::endl;
    }

    // operator&, operator|, IsDisjointWith
    {
        ImmutableSet<int> a = {1, 3};
        ImmutableSet<int> b = {1, 3, 2};
        ImmutableSet<int> c = {3, 2};
        ImmutableSet<int> g = {4, 5};

        std::cout << "4.1)  " << (a & a) << std::endl;
        std::cout << "4.2)  " << (a & b) << std::endl;
        std::cout << "4.3)  " << (a & c) << std::endl;
        std::cout << "4.4)  " << (a | a) << std::endl;
        std::cout << "4.5)  " << (a | b) << std::endl;
        std::cout << "4.6)  " << (a | c) << std::endl;
        std::cout << "4.7)  " << std::boolalpha << a.IsDisjointWith(b) << std::endl;
        std::cout << "4.8)  " << std::boolalpha << a.IsDisjointWith(g) << std::endl;

        ImmutableSet<double> d = {1.5, 3.5};
        ImmutableSet<double> e = {1.5, 3.5, 2.4};
        ImmutableSet<double> f = {3.5, 2.5};
        ImmutableSet<double> h = {4.5, 5.5};

        std::cout << "4.9)  " << (d & e) << std::endl;
        std::cout << "4.10) " << (d & f) << std::endl;
        std::cout << "4.11) " << (d | e) << std::endl;
        std::cout << "4.12) " << (d | f) << std::endl;
        std::cout << "4.13) " << (d | e | f) << std::endl;
        std::cout << "4.14) " << std::boolalpha << d.IsDisjointWith(e) << std::endl;
        std::cout << "4.15) " << std::boolalpha << d.IsDisjointWith(h) << std::endl;
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

// [YOUR CODE WILL BE PLACED HERE]

template <typename T>
ImmutableSet<T>::ImmutableSet(std::initializer_list<T> l)
{
    repr_ = l;
    std::sort(repr_.begin(), repr_.end());
    repr_.resize(std::distance(repr_.begin(), std::unique(repr_.begin(), repr_.end())));
}

template <typename T>
ImmutableSet<T>::ImmutableSet(const std::vector<T> &values)
{
    repr_ = values;
    std::sort(repr_.begin(), repr_.end());
    repr_.resize(std::distance(repr_.begin(), std::unique(repr_.begin(), repr_.end())));
}

template <typename T>
bool ImmutableSet<T>::Contains(const T &value) const
{
    return std::binary_search(this->repr_.begin(), this->repr_.end(), value);
}

template <typename T>
bool ImmutableSet<T>::IsDisjointWith(const ImmutableSet<T> &other) const
{
    if (this->Size() <= other.Size())
    {
        for (int i = 0; i < this->Size(); i++)
        {
            if (other.Contains(this->Values()[i]))
            {
                return false;
            }
        }
    }
    else
    {
        for (int i = 0; i < other.Size(); i++)
        {
            if (this->Contains(other.Values()[i]))
            {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
bool operator==(const ImmutableSet<T> &lhs, const ImmutableSet<T> &rhs)
{
    if (lhs.Size() != rhs.Size())
    {
        return false;
    }
    for (int i = 0; i < rhs.Size(); i++)
    {
        if (!rhs.Contains(lhs.Values()[i]))
        {
            return false;
        }
    }
    return true;
}

template <typename T>
bool operator!=(const ImmutableSet<T> &lhs, const ImmutableSet<T> &rhs)
{
    if (lhs.Size() != rhs.Size())
    {
        return true;
    }
    for (int i = 0; i < rhs.Size(); i++)
    {
        if (!rhs.Contains(lhs.Values()[i]))
        {
            return true;
        }
    }
    return false;
}

template <typename T>
bool operator<=(const ImmutableSet<T> &lhs, const ImmutableSet<T> &rhs)
{
    if (rhs.Size() < lhs.Size())
    {
        return false;
    }
    for (int i = 0; i < lhs.Size(); i++)
    {
        if (!rhs.Contains(lhs.Values()[i]))
        {
            return false;
        }
    }
    return true;
}

template <typename T>
bool operator>=(const ImmutableSet<T> &lhs, const ImmutableSet<T> &rhs)
{
    if (rhs.Size() > lhs.Size())
    {
        return false;
    }
    for (int i = 0; i < rhs.Size(); i++)
    {
        if (!lhs.Contains(rhs.Values()[i]))
        {
            return false;
        }
    }
    return true;
}

template <typename T>
ImmutableSet<T> operator&(const ImmutableSet<T> &lhs, const ImmutableSet<T> &rhs)
{
    std::vector<T> temp;
    if (lhs.Size() <= rhs.Size())
    {
        for (int i = 0; i < lhs.Size(); i++)
        {
            if (rhs.Contains(lhs.Values()[i]))
            {
                temp.push_back(lhs.Values()[i]);
            }
        }
    }
    else
    {
        for (int i = 0; i < rhs.Size(); i++)
        {
            if (lhs.Contains(rhs.Values()[i]))
            {
                temp.push_back(rhs.Values()[i]);
            }
        }
    }
    ImmutableSet<T> ans(temp);
    return ans;
}

template <typename T>
ImmutableSet<T> operator|(const ImmutableSet<T> &lhs, const ImmutableSet<T> &rhs)
{
    std::vector<T> temp = lhs.Values();
    for (int i = 0; i < rhs.Size(); i++)
    {
        temp.push_back(rhs.Values()[i]);
    }
    ImmutableSet<T> ans(temp);
    return ans;
}
