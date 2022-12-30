#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    vector<string> ans;
    double a, b, c, d;
    string trash;
    int WA = 0;
    getline(cin, trash);
    while (getline(cin, trash, '$'))
    {
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
        if (abs(a + b + c - d) > 0.00001)
        {
            WA++;
        }
        cin.ignore();
    }
    cout << WA;
}