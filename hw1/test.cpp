#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    string trash;
    double a, b, c, d;
    getline(cin, trash, '$');
    cin >> a;
    if (trash == "-")
    {
        a = -a;
    }
    getline(cin, trash, ',');
    getline(cin, trash, '$');
    cin >> b;
    if (trash == "-")
    {
        b = -b;
    }
    getline(cin, trash, ',');
    getline(cin, trash, '$');
    cin >> c;
    if (trash == "-")
    {
        c = -c;
    }
    getline(cin, trash, ',');
    getline(cin, trash, '$');
    cin >> d;
    if (trash == "-")
    {
        d = -d;
    }
    cout << a << ',' << b << ',' << c << ',' << d;
    cout << a + b + c << endl;
    if ((abs(a + b + c - d) < 0.00001))
    {
        cout << "yes";
    }
}