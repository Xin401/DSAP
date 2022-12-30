#include <sstream>
#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class FixedPoint
{
public:
    FixedPoint() : repr_{0} {}
    FixedPoint(double val)
    {
        repr_ = std::round(val * 100);
    }
    explicit FixedPoint(long long repr) : repr_{repr}
    {
    }
    std::string ToString() const
    {
        std::ostringstream out;
        out.precision(2);
        out << std::fixed << (repr_ / 100.);
        return out.str();
    }

    long long GetRepr() const
    {
        return repr_;
    }

private:
    long long repr_;
};

FixedPoint operator+(const FixedPoint &lhs, const FixedPoint &rhs)
{
    return FixedPoint{lhs.GetRepr() + rhs.GetRepr()};
}
FixedPoint operator-(const FixedPoint &lhs, FixedPoint &rhs)
{
    return FixedPoint{lhs.GetRepr() - rhs.GetRepr()};
}
FixedPoint operator*(const FixedPoint &lhs, const FixedPoint &rhs)
{
    long long repr = lhs.GetRepr() * rhs.GetRepr();
    if (repr >= 0)
    {
        return FixedPoint{(repr + 50) / 100};
    }
    return FixedPoint{(repr - 50) / 100};
}
FixedPoint operator/(const FixedPoint &lhs, const FixedPoint &rhs)
{
    long long repr = lhs.GetRepr() * 1000 / rhs.GetRepr();
    if (repr >= 0)
    {
        return FixedPoint{(repr + 5) / 10};
    }
    return FixedPoint{(repr - 5) / 10};
}
bool operator>(const FixedPoint &lhs, const FixedPoint &rhs)
{
    return lhs.GetRepr() > rhs.GetRepr();
}
bool operator<(const FixedPoint &lhs, const FixedPoint &rhs)
{
    return lhs.GetRepr() < rhs.GetRepr();
}
bool operator==(const FixedPoint &lhs, const FixedPoint &rhs)
{
    return lhs.GetRepr() == rhs.GetRepr();
}
std::ostream &operator<<(std::ostream &os, const FixedPoint &p)
{
    return os << p.ToString();
}
std::istream &operator>>(std::istream &is, FixedPoint &p)
{
    double val;
    is >> val;
    p = FixedPoint{val};
    return is;
}

std::string Evaluate(std::string &cell, string table[1000][26], int l, int k, int mark[1000], int j);

int main()
{
    std::string line;
    string table[1000][26];
    int mark[1000];
    int j = 0;
    int column = 0;
    while (getline(std::cin, line))
    {
        size_t begin_pos = 0;
        int i = 0;
        while (true)
        {
            size_t end_pos = line.find(',', begin_pos);
            table[j][i] = line.substr(begin_pos, end_pos - begin_pos);
            if (end_pos == std::string::npos)
            {
                mark[j] = i;
                break;
            }
            begin_pos = end_pos + 1;
            i++;
        }
        j++;
    }

    for (int l = 0; l < j; l++)
    {
        for (int k = 0; k <= mark[l]; k++)
        {
            if (table[l][k][0] != '#')
                cout << Evaluate(table[l][k], table, l, k, mark, j);
            else
            {
                string a = table[l][k];
                a.erase(a.begin());
                cout << a;
            }
            if (k != mark[l])
            {
                cout << ',';
            }
        }
        cout << endl;
    }
}

using namespace std;
std::string Evaluate(std::string &cell, string table[1000][26], int l, int k, int mark[1000], int j)
{
    if (cell == "")
    {
        return cell;
    }
    if (cell.find("ERROR") != string::npos)
    {
        return "ERROR";
    }
    if (cell.find_first_of("0987654321") == string::npos)
    {
        return "ERROR";
    }
    if (cell[0] == '#')
    {
        return "ERROR";
    }
    if (cell[0] == '=')
    {
        if (cell.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos)
        {
            string val1;
            string val2;
            string formula;
            size_t fEng = cell.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
            size_t op = cell.find_first_of("+-*/<>");
            string num1;
            if (fEng < op)
            {
                num1 = cell.substr(fEng + 1, op - fEng - 1);
                if (stoi(num1) - 1 == l && cell[fEng] - 65 == k)
                {
                    return "ERROR";
                }
                val1 = Evaluate(table[stoi(num1) - 1][cell[fEng] - 65], table, l, k, mark, j);
                if (val1 == "true" || val1 == "false" || val1 == "ERROR")
                {
                    return "ERROR";
                }
                if (stoi(num1) - 1 >= j || cell[fEng] - 65 > mark[stoi(num1) - 1])
                {
                    return "ERROR";
                }
                val2 = cell.substr(op + 1);
                if (cell.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ", op + 1) != string ::npos)
                {
                    size_t sEng = cell.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ", fEng + 1);
                    string num2 = cell.substr(sEng + 1);
                    if (stoi(num2) - 1 == l && cell[sEng] - 65 == k)
                    {
                        return "ERROR";
                    }
                    val2 = Evaluate(table[stoi(num2) - 1][cell[sEng] - 65], table, l, k, mark, j);
                    if (val2 == "true" || val2 == "false" || val2 == "ERROR")
                    {
                        return "ERROR";
                    }
                    if (stoi(num2) - 1 >= j || cell[sEng] - 65 > mark[stoi(num2) - 1])
                    {
                        return "ERROR";
                    }
                }
                formula = '=' + val1 + cell[op] + val2;
                return Evaluate(formula, table, l, k, mark, j);
            }
            else
            {
                num1 = cell.substr(fEng + 1);
                if (stoi(num1) - 1 == l && cell[fEng] - 65 == k)
                {
                    return "ERROR";
                }
                if (stoi(num1) - 1 >= j || cell[fEng] - 65 > mark[stoi(num1) - 1])
                {
                    return "ERROR";
                }
                val1 = Evaluate(table[stoi(num1) - 1][cell[fEng] - 65], table, l, k, mark, j);
                if (val1 == "true" || val1 == "false" || val1 == "ERROR")
                {
                    return "ERROR";
                }
                val2 = cell.substr(1, op - 1);
                formula = '=' + val2 + cell[op] + val1;
                return Evaluate(formula, table, l, k, mark, j);
            }
        }
        string n1 = "";
        string n2 = "";
        size_t op = cell.find_first_of("+-*/<>");
        if (op == 1)
        {
            op = cell.find_first_of("+-*/><", op + 1);
        }
        string ans;
        bool havedot1 = false;
        bool havedot2 = false;
        for (int i = 1; i < op; i++)
        {
            if (cell[i] != '.')
                n1.push_back(cell[i]);
            else
                havedot1 = true;
        }
        for (int i = op + 1; i < cell.length(); i++)
        {
            if (cell[i] != '.')
                n2.push_back(cell[i]);
            else
                havedot2 = true;
        }
        if (n1.find_first_not_of("09876544321-.") != string::npos || n2.find_first_not_of("09876544321-.") != string::npos)
        {
            return "ERROR";
        }
        long long number1 = stoll(n1);
        long long number2 = stoll(n2);
        if (!havedot1)
        {
            number1 *= 100;
        }
        if (!havedot2)
        {
            number2 *= 100;
        }
        FixedPoint f1(number1);
        FixedPoint f2(number2);
        if (cell[op] == '+')
        {
            FixedPoint answer = f1 + f2;
            if (answer > 100000 || answer < -100000)
            {
                ans = "ERROR";
            }
            else
            {
                ans = answer.ToString();
            }
        }
        if (cell[op] == '-')
        {
            FixedPoint answer = f1 - f2;
            if (answer > 100000 || answer < -100000)
            {
                ans = "ERROR";
            }
            else
            {
                ans = answer.ToString();
            }
        }
        if (cell[op] == '*')
        {

            FixedPoint answer = f1 * f2;
            if (answer > 100000 || answer < -100000)
            {
                ans = "ERROR";
            }
            else
            {
                ans = answer.ToString();
            }
        }
        if (cell[op] == '/')
        {
            if (f2.GetRepr() == 0)
            {
                ans = "ERROR";
            }
            else
            {
                FixedPoint answer = f1 / f2;
                if (answer > 100000 || answer < -100000)
                {
                    ans = "ERROR";
                }
                else
                {
                    ans = answer.ToString();
                }
            }
        }
        if (cell[op] == '>')
        {
            if (f1 > f2)
            {
                ans = "true";
            }
            else
            {
                ans = "false";
            }
        }
        if (cell[op] == '<')
        {
            if (f1 < f2)
            {
                ans = "true";
            }
            else
            {
                ans = "false";
            }
        }
        return ans;
    }
    if (cell.find_first_not_of("0987654321.-") == string::npos)
    {
        return cell;
    }
    else
    {
        return "ERROR";
    }
}
