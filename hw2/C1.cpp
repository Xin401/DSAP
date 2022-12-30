#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class USDollar
{
private:
    long long repr_;

public:
    USDollar();
    USDollar(string val);
    USDollar(const char *val);
    USDollar(int val);
    USDollar(double val);
    USDollar(float val);
    USDollar(long long val);
    operator double();
    USDollar operator+(const USDollar &rhs) const;
    USDollar operator-(const USDollar &rhs) const;
    USDollar operator*(const USDollar &rhs) const;
    USDollar operator/(const USDollar &rhs) const;
    bool operator<(const USDollar &rhs) const;
    bool operator>(const USDollar &rhs) const;
    bool operator==(const USDollar &rhs) const;
    bool operator!=(const USDollar &rhs) const;
    long long GetRepr() const;
};
std::ostream &operator<<(std::ostream &os, const USDollar &p);

USDollar::USDollar()
{
    repr_ = 0;
}
USDollar::USDollar(string val)
{
    size_t money = val.find_first_of('$');
    double value;
    val.erase(money, 1);
    value = stod(val);
    repr_ = round(value * 100);
}
USDollar::USDollar(const char *value)
{
    string val;
    val = value;
    size_t money = val.find_first_of('$');
    double repr;
    val.erase(money, 1);
    repr = stod(val);
    repr_ = round(repr * 100);
}
USDollar::USDollar(int val)
{
    repr_ = val * 100;
}
USDollar::USDollar(double val)
{
    val *= 100;
    repr_ = round(val);
}

USDollar::USDollar(float val)
{
    val *= 100;
    repr_ = round(val);
}

USDollar::USDollar(long long val)
{
    repr_ = val;
}

USDollar::operator double()
{
    return (static_cast<double>(this->GetRepr()) / 100);
}

long long USDollar::GetRepr() const
{
    return repr_;
}
USDollar USDollar::operator+(const USDollar &rhs) const
{
    USDollar temp(this->GetRepr() + rhs.GetRepr());
    return temp;
}
USDollar USDollar::operator-(const USDollar &rhs) const
{
    USDollar temp(this->GetRepr() - rhs.GetRepr());
    return temp;
}
USDollar USDollar::operator*(const USDollar &rhs) const
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
    USDollar temp(repr);
    return temp;
}
USDollar USDollar::operator/(const USDollar &rhs) const
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
    USDollar temp(repr_);
    return temp;
}
bool USDollar::operator<(const USDollar &rhs) const
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
bool USDollar::operator>(const USDollar &rhs) const
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
bool USDollar::operator==(const USDollar &rhs) const
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
bool USDollar::operator!=(const USDollar &rhs) const
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
std::ostream &operator<<(std::ostream &os, const USDollar &p)
{
    bool minus = false;
    long two = 0;
    long one = 0;
    long long three = 0;
    if (p.GetRepr() > 0)
    {
        one = p.GetRepr() % 10;
        two = (p.GetRepr() % 100) / 10;
        three = p.GetRepr() / 100;
    }
    else
    {
        one = p.GetRepr() % 10;
        two = (p.GetRepr() % 100) / 10;
        three = p.GetRepr() / 100;
        one = -one;
        two = -two;
        three = -three;
    }
    if (p.GetRepr() < 0)
    {
        minus = true;
    }
    if (!minus)
    {
        os << '$' << three << '.' << two << one;
    }
    else
    {
        os << '-' << '$' << three << '.' << two << one;
    }
    return os;
}