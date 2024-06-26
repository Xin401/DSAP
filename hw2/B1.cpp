#include <iostream>

/*
 * 十進位表示的帶二位小數有號定點數型態 (Signed Decimal Fixed-Point Number)
 */
class FixedPoint
{
    static const int kInverseOfScalingFactor = 100;

public:
    FixedPoint(double val);
    explicit FixedPoint(long long repr);
    FixedPoint operator+(const FixedPoint &rhs) const;
    FixedPoint operator-(const FixedPoint &rhs) const;
    FixedPoint operator*(const FixedPoint &rhs) const;
    FixedPoint operator/(const FixedPoint &rhs) const;
    bool operator<(const FixedPoint &rhs) const;
    bool operator>(const FixedPoint &rhs) const;
    bool operator==(const FixedPoint &rhs) const;
    bool operator!=(const FixedPoint &rhs) const;
    long long GetRepr() const;

private:
    long long repr_;
};

std::ostream &operator<<(std::ostream &os, const FixedPoint &p);

void Test1();
void Test2();
void Test3();
void Test4();
void Test5();
void Test6();
void Test7();
void Test8();

int main()
{
    int id;
    std::cin >> id;
    void (*f[])() = {Test1, Test2, Test3, Test4, Test5, Test6, Test7, Test8};
    f[id - 1]();
}

namespace Feis
{ /* HIDDEN */
}

void Test1()
{
    // FixedPoint 物件可用 double 值初始化
    // - 值最多有兩位小數，且其 100 倍在 long long 表示範圍內。不符合則是《未定義行為》(UB: Undefined Behavior)
    {
        FixedPoint p = 100.08;
        std::cout << p << std::endl; // 印出 "100.08"

        FixedPoint q1 = 80.86, q2 = -70.83;
        std::cout << q1 << "\t" << q2 << std::endl; // 印出 "80.86	-70.83"
    }

    // FixedPoint 物件可用 long long 值初始化
    // - 因為是兩位小數的十進位定點數，真實值為此 long long 值再除以 100
    {
        FixedPoint p(10008LL);
        std::cout << p << std::endl; // 印出 "100.08"

        FixedPoint q1(8086LL), q2(-7083LL);
        std::cout << q1 << "\t" << q2 << std::endl; // 印出 "80.86	-70.83"
    }

    // FixedPoint 物件可用 GetRepr() 操作取得其內部表示的 long long 整數值
    // - 因為是帶兩位小數的定點數，此 long long 整數應為真實值的 100 倍
    {
        FixedPoint p = 458.83;
        std::cout << p.GetRepr() << std::endl; // 印出 "45883"

        FixedPoint q = -831.32;
        std::cout << q.GetRepr() << std::endl; // 印出 "-83132"
    }

    // FixedPoint 物件可以進行比較運算 (>, <, ==, !=)
    {
        FixedPoint p = 0.1, q = 0.1, r = 0.3;
        std::cout << std::boolalpha << (p > r) << std::endl;  // 印出 "false"
        std::cout << std::boolalpha << (p < r) << std::endl;  // 印出 "true"
        std::cout << std::boolalpha << (p == r) << std::endl; // 印出 "false"
        std::cout << std::boolalpha << (p == q) << std::endl; // 印出 "true"
        std::cout << std::boolalpha << (p != q) << std::endl; // 印出 "false"
    }

    // FixedPoint 物件可以相加 (+) 與相減 (-)
    // - 運算元與運算結果值最多有兩位小數，且其 100 倍在 long long 表示範圍內。
    {
        FixedPoint q1 = 82.91, q2 = 84.77;
        std::cout << (q1 + q2) << std::endl;      // 印出 "167.68"
        std::cout << (q1 + q2 - q1) << std::endl; // 印出 "84.77"
    }

    // FixedPoint 物件可以相乘 (*) 與相除 (/)
    // - 每次執行完運算都會四捨五入到小數點後第二位
    // - 運算元與運算結果值最多有兩位小數，且其 100 倍在 long long 表示範圍內。
    // - 除以 0.00 是《未定義行為》(UB: Undefined Behavior)
    {
        FixedPoint q1 = 82.91, q2 = 84.77;
        std::cout << (q1 * q2) << std::endl; // 印出 "7028.28"
        std::cout << (q1 / q2) << std::endl; // 印出 "0.98"
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

#include <cmath>
FixedPoint::FixedPoint(double val)
{
    repr_ = round(val * kInverseOfScalingFactor);
}
FixedPoint::FixedPoint(long long repr)
{
    repr_ = repr;
}
long long FixedPoint::GetRepr() const
{
    return repr_;
}
FixedPoint FixedPoint::operator+(const FixedPoint &rhs) const
{
    FixedPoint temp(GetRepr() + rhs.GetRepr());
    return temp;
}
FixedPoint FixedPoint::operator-(const FixedPoint &rhs) const
{
    FixedPoint temp(this->GetRepr() - rhs.GetRepr());
    return temp;
}
FixedPoint FixedPoint::operator*(const FixedPoint &rhs) const
{
    long long repr = 0;
    repr = this->GetRepr() * rhs.GetRepr();
    if (repr < 0)
    {
        repr -= 50;
    }
    else
    {
        repr += 50;
    }
    repr /= 100;
    FixedPoint temp(repr);
    return temp;
}
FixedPoint FixedPoint::operator/(const FixedPoint &rhs) const
{
    double repr = 0;
    long long repr_;
    repr = static_cast<double>(this->GetRepr()) / rhs.GetRepr();
    repr *= 100;
    if (repr < 0)
    {
        repr -= 0.5;
    }
    else
    {
        repr += 0.5;
    }
    repr_ = repr;
    FixedPoint temp(repr_);
    return temp;
}
bool FixedPoint::operator<(const FixedPoint &rhs) const
{
    if (this->GetRepr() < rhs.GetRepr())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool FixedPoint::operator>(const FixedPoint &rhs) const
{
    if (this->GetRepr() > rhs.GetRepr())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool FixedPoint::operator==(const FixedPoint &rhs) const
{
    if (this->GetRepr() == rhs.GetRepr())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool FixedPoint::operator!=(const FixedPoint &rhs) const
{
    if (this->GetRepr() != rhs.GetRepr())
    {
        return true;
    }
    else
    {
        return false;
    }
}
std::ostream &operator<<(std::ostream &os, const FixedPoint &p)
{
    bool minus = false;
    long two = 0;
    long one = 0;
    long long three = 0;
    if (p.GetRepr() > 0)
    {
        one = p.GetRepr() % 10;
        two = (p.GetRepr() % 100) / 10;
    }
    else
    {
        one = p.GetRepr() % 10;
        two = (p.GetRepr() % 100) / 10;
        one = -one;
        two = -two;
    }
    if (p.GetRepr() < 0 && p.GetRepr() > -99)
    {
        minus = true;
    }
    three = p.GetRepr() / 100;
    if (!minus)
    {
        os << three << '.' << two << one;
    }
    else
    {
        os << '-' << three << '.' << two << one;
    }
    return os;
}