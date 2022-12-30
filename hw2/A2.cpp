#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
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

FixedPoint calculate(FixedPoint a, FixedPoint b, char op)
{
    FixedPoint ans(0.);
    switch (op)
    {
    case '+':
        ans = a + b;
        break;
    case '-':
        ans = a - b;
        break;
    case '*':
        ans = a * b;
        break;
    case '/':
        if (b.GetRepr() == 0)
        {
            return INT_MIN;
        }
        ans = a / b;
        break;
    }
    return ans;
}
int judgeRank(char a)
{
    int rank = 0;
    if (a == '*' || a == '/')
    {
        rank = 3;
    }
    if (a == '+' || a == '-')
    {
        rank = 2;
    }
    if (a == '<' || a == '>')
    {
        rank = 1;
    }
    return rank;
}
int main()
{
    string formula;
    string op = "+-*/<>";
    while (cin >> formula)
    {
        vector<string> s(3);
        vector<int> rank(2);
        size_t first = formula.find_first_of(op);
        if (first == 0)
        {
            first = formula.find_first_of(op, first + 1);
        }
        rank[0] = judgeRank(formula[first]);
        size_t second = formula.find_first_of(op, first + 2);
        rank[1] = judgeRank(formula[second]);
        s[0] = formula.substr(0, first);
        s[1] = formula.substr(first + 1, second - first - 1);
        s[2] = formula.substr(second + 1);
        for (int i = 0; i < 3; i++)
        {
            size_t dot = s[i].find('.');
            s[i].erase(dot, 1);
        }
        FixedPoint f1(stoll(s[0]));
        FixedPoint f2(stoll(s[1]));
        FixedPoint f3(stoll(s[2]));
        if (rank[0] == 1 && rank[1] == 1)
        {
            bool ans1 = false;
            bool ans2 = false;
            if (formula[first] == '<')
            {
                if (f1 < f2)
                {
                    ans1 = true;
                }
            }
            else
            {
                if (f1 > f2)
                {
                    ans1 = true;
                }
            }
            if (formula[second] == '<')
            {
                if (f2 < f3)
                {
                    ans2 = true;
                }
            }
            else
            {
                if (f2 > f3)
                {
                    ans2 = true;
                }
            }
            if (ans1 && ans2)
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
            continue;
        }
        // calculator
        if (rank[0] >= rank[1] && rank[1] != 1)
        {
            FixedPoint ans(0.);
            bool error = false;
            switch (formula[first])
            {
            case '+':
                ans = f1 + f2;
                break;
            case '-':
                ans = f1 - f2;
                break;
            case '*':
                ans = f1 * f2;
                break;
            case '/':
                if (f2.GetRepr() == 0)
                {
                    error = true;
                    cout << "ERROR" << endl;
                    break;
                }
                ans = f1 / f2;
                break;
            }
            if (!error)
            {
                switch (formula[second])
                {
                case '+':
                    ans = ans + f3;
                    break;
                case '-':
                    ans = ans - f3;
                    break;
                case '*':
                    ans = ans * f3;
                    break;
                case '/':
                    if (f3.GetRepr() == 0)
                    {
                        error = true;
                        cout << "ERROR" << endl;
                        break;
                    }
                    ans = ans / f3;
                    break;
                }
            }
            if (!error)
            {
                cout << ans << endl;
            }
        }
        if (rank[0] < rank[1] && rank[0] != 1)
        {
            FixedPoint ans(0.);
            bool error = false;
            switch (formula[second])
            {
            case '+':
                ans = f2 + f3;
                break;
            case '-':
                ans = f2 - f3;
                break;
            case '*':
                ans = f2 * f3;
                break;
            case '/':
                if (f3.GetRepr() == 0)
                {
                    error = true;
                    cout << "ERROR" << endl;
                    break;
                }
                ans = f2 / f3;
                break;
            }
            if (!error)
            {
                switch (formula[first])
                {
                case '+':
                    ans = f1 + ans;
                    break;
                case '-':
                    ans = f1 - ans;
                    break;
                case '*':
                    ans = f1 * ans;
                    break;
                case '/':
                    if (ans.GetRepr() == 0)
                    {
                        error = true;
                        cout << "ERROR" << endl;
                        break;
                    }
                    ans = f1 / ans;
                    break;
                }
                if (!error)
                {
                    cout << ans << endl;
                }
            }
        }
        if (rank[0] < rank[1] && rank[0] == 1)
        {
            FixedPoint ans(0.);
            bool error = false;
            switch (formula[second])
            {
            case '+':
                ans = f2 + f3;
                break;
            case '-':
                ans = f2 - f3;
                break;
            case '*':
                ans = f2 * f3;
                break;
            case '/':
                if (f3.GetRepr() == 0)
                {
                    error = true;
                    cout << "ERROR" << endl;
                    break;
                }
                ans = f2 / f3;
                break;
            }
            if (!error)
            {
                if (formula[first] == '<')
                {
                    if (f1 < ans)
                    {
                        cout << "true" << endl;
                    }
                    else
                    {
                        cout << "false" << endl;
                    }
                }
                else
                {
                    if (f1 > ans)
                    {
                        cout << "true" << endl;
                    }
                    else
                    {
                        cout << "false" << endl;
                    }
                }
            }
        }

        if (rank[0] > rank[1] && rank[1] == 1)
        {
            FixedPoint ans(0.);
            bool error = false;
            switch (formula[first])
            {
            case '+':
                ans = f1 + f2;
                break;
            case '-':
                ans = f1 - f2;
                break;
            case '*':
                ans = f1 * f2;
                break;
            case '/':
                if (f2.GetRepr() == 0)
                {
                    error = true;
                    cout << "ERROR" << endl;
                    break;
                }
                ans = f1 / f2;
                break;
            }
            if (!error)
            {
                if (formula[second] == '<')
                {
                    if (ans < f3)
                    {
                        cout << "true" << endl;
                    }
                    else
                    {
                        cout << "false" << endl;
                    }
                }
                else
                {
                    if (ans > f3)
                    {
                        cout << "true" << endl;
                    }
                    else
                    {
                        cout << "false" << endl;
                    }
                }
            }
        }
    }
}

FixedPoint::FixedPoint(double val)
{
    repr_ = val * kInverseOfScalingFactor;
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
    if (repr > 0)
    {
        repr += 50;
    }
    double repr_ = repr / 100;
    repr = static_cast<long long>(repr_);
    FixedPoint temp(repr);
    return temp;
}
FixedPoint FixedPoint::operator/(const FixedPoint &rhs) const
{
    double repr = 0;
    long long repr_ = 0;
    repr = static_cast<double>(this->GetRepr()) / static_cast<double>(rhs.GetRepr());
    if (repr > 0)
    {
        repr += 0.005;
    }
    if (repr < 0)
    {
        repr -= 0.005;
    }
    FixedPoint temp(repr);
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