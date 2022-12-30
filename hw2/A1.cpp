#include <string>
#include <iostream>
#include <cmath>
using namespace std;

void add(string formula)
{
    int ans;
    int ret;
    string n1;
    string n2;
    int d1;
    int d2;
    int anspoint;
    bool minus = false;
    for (int i = 0; i < formula.length(); i++)
    {
        if (formula[i] == '+')
        {
            ret = i;
        }
    }
    for (int i = 0; i < ret; i++)
    {
        if (formula[i] != '.')
        {
            n1.push_back(formula[i]);
        }
    }
    for (int i = ret + 1; i < formula.length(); i++)
    {
        if (formula[i] != '.')
        {
            n2.push_back(formula[i]);
        }
    }
    d1 = stoi(n1);
    d2 = stoi(n2);
    ans = d1 + d2;
    if (ans < 0)
    {
        minus = true;
    }
    anspoint = abs(ans) % 100;
    ans = abs(ans) / 100;
    if (anspoint >= 10)
    {
        if (!minus)
            cout << ans << '.' << anspoint << endl;
        else
            cout << '-' << ans << '.' << anspoint << endl;
    }
    if (anspoint != 0 && abs(anspoint) < 10)
    {
        if (!minus)
            cout << ans << ".0" << anspoint << endl;
        else
            cout << '-' << ans << ".0" << anspoint << endl;
    }
    if (anspoint == 0)
    {
        if (!minus)
            cout << ans << ".00" << endl;
        else
            cout << '-' << ans << ".00" << endl;
    }
}
void subtract(string formula)
{
    int ans;
    int ret;
    string n1;
    string n2;
    int d1;
    int d2;
    int anspoint;
    bool minus = false;
    for (int i = 0; i < formula.length(); i++)
    {
        if (formula[i] == '-' && i != 0)
        {
            ret = i;
            break;
        }
    }
    for (int i = 0; i < ret; i++)
    {
        if (formula[i] != '.')
        {
            n1.push_back(formula[i]);
        }
    }
    for (int i = ret + 1; i < formula.length(); i++)
    {
        if (formula[i] != '.')
        {
            n2.push_back(formula[i]);
        }
    }
    d1 = stoi(n1);
    d2 = stoi(n2);
    ans = d1 - d2;
    if (ans < 0)
    {
        minus = true;
    }
    anspoint = abs(ans) % 100;
    ans = abs(ans) / 100;
    if (anspoint >= 10)
    {
        if (!minus)
            cout << ans << '.' << anspoint << endl;
        else
            cout << '-' << ans << '.' << anspoint << endl;
    }
    if (anspoint != 0 && abs(anspoint) < 10)
    {
        if (!minus)
            cout << ans << ".0" << anspoint << endl;
        else
            cout << '-' << ans << ".0" << anspoint << endl;
    }
    if (anspoint == 0)
    {
        if (!minus)
            cout << ans << ".00" << endl;
        else
            cout << '-' << ans << ".00" << endl;
    }
}
void time(string formula)
{
    long long ans;
    int ret;
    string n1;
    string n2;
    double d1;
    double d2;
    int anspoint;
    bool minus;
    for (int i = 0; i < formula.length(); i++)
    {
        if (formula[i] == '*')
        {
            ret = i;
        }
    }
    for (int i = 0; i < ret; i++)
    {
        if (formula[i] != '.')
        {
            n1.push_back(formula[i]);
        }
    }
    for (int i = ret + 1; i < formula.length(); i++)
    {
        if (formula[i] != '.')
        {
            n2.push_back(formula[i]);
        }
    }
    d1 = stoi(n1);
    d2 = stoi(n2);
    ans = d1 * d2;
    if (ans > 0)
    {
        ans += 50;
    }
    else
    {
        ans -= 50;
    }
    ans /= 100;
    anspoint = ans % 100;
    if (ans < 0 && ans / 100 == 0.)
    {
        minus = true;
    }
    ans /= 100;
    if (anspoint != 0 && abs(anspoint) >= 10)
    {
        if (!minus)
            cout << ans << '.' << abs(anspoint) << endl;
        else
            cout << '-' << ans << '.' << abs(anspoint) << endl;
    }
    if (anspoint != 0 && abs(anspoint) < 10)
    {
        if (!minus)
            cout << ans << ".0" << abs(anspoint) << endl;
        else
            cout << '-' << ans << ".0" << abs(anspoint) << endl;
    }
    if (anspoint == 0)
    {
        cout << ans << ".00" << endl;
    }
}
void divide(string formula)
{
    double temp;
    int ret;
    string n1;
    string n2;
    double d1;
    double d2;
    int ans;
    int anspoint;
    bool minus = false;
    for (int i = 0; i < formula.length(); i++)
    {
        if (formula[i] == '/')
        {
            ret = i;
        }
    }
    for (int i = 0; i < ret; i++)
    {
        if (formula[i] != '.')
        {
            n1.push_back(formula[i]);
        }
    }
    for (int i = ret + 1; i < formula.length(); i++)
    {
        if (formula[i] != '.')
        {
            n2.push_back(formula[i]);
        }
    }
    d1 = stod(n1);
    d2 = stod(n2);
    if (d2 == 0.)
    {
        cout << "ERROR" << endl;
    }
    else
    {
        temp = d1 / d2;
        temp *= 100;
        if (temp > 0)
        {
            temp += 0.5;
        }
        else
        {
            temp -= 0.5;
        }
        ans = temp;
        if (ans < 0 && ans / 100 == 0)
        {
            minus = true;
        }
        anspoint = ans % 100;
        ans /= 100;
        if (anspoint != 0 && abs(anspoint) >= 10)
        {
            if (!minus)
                cout << ans << '.' << abs(anspoint) << endl;
            else
                cout << '-' << ans << '.' << abs(anspoint) << endl;
        }
        if (anspoint != 0 && abs(anspoint) < 10)
        {
            if (!minus)
                cout << ans << ".0" << abs(anspoint) << endl;
            else
                cout << '-' << ans << ".0" << abs(anspoint) << endl;
        }
        if (anspoint == 0)
        {
            cout << ans << ".00" << endl;
        }
    }
}
bool bigger(string formula)
{
    bool ans;
    int ret;
    string n1;
    string n2;
    double d1;
    double d2;
    for (int i = 0; i < formula.length(); i++)
    {
        if (formula[i] == '>')
        {
            ret = i;
        }
    }
    for (int i = 0; i < ret; i++)
    {
        n1.push_back(formula[i]);
    }
    for (int i = ret + 1; i < formula.length(); i++)
    {
        n2.push_back(formula[i]);
    }
    d1 = stod(n1);
    d2 = stod(n2);
    ans = (d1 > d2 ? true : false);
    return ans;
}
bool smaller(string formula)
{
    bool ans;
    int ret;
    string n1;
    string n2;
    double d1;
    double d2;
    for (int i = 0; i < formula.length(); i++)
    {
        if (formula[i] == '<')
        {
            ret = i;
        }
    }
    for (int i = 0; i < ret; i++)
    {
        n1.push_back(formula[i]);
    }
    for (int i = ret + 1; i < formula.length(); i++)
    {
        n2.push_back(formula[i]);
    }
    d1 = stod(n1);
    d2 = stod(n2);
    ans = (d1 < d2 ? true : false);
    return ans;
}
int main()
{
    string formula;
    while (cin >> formula)
    {
        for (int i = 0; i < formula.length(); i++)
        {
            if (formula[i] == '+')
            {
                add(formula);
                break;
            }
            if (formula[i] == '-' && i != 0)
            {
                subtract(formula);
                break;
            }
            if (formula[i] == '*')
            {
                time(formula);
                break;
            }
            if (formula[i] == '/')
            {
                divide(formula);
                break;
            }
            if (formula[i] == '>')
            {
                if (bigger(formula))
                {
                    cout << "true" << endl;
                }
                else
                {
                    cout << "false" << endl;
                }
                break;
            }
            if (formula[i] == '<')
            {
                if (smaller(formula))
                {
                    cout << "true" << endl;
                }
                else
                {
                    cout << "false" << endl;
                }
                break;
            }
        }
    }
}