#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    vector<string> ans;
    double a, b, c, d;
    while (cin >> a)
    {
        cin >> b >> c >> d;
        if (abs(a + b + c - d) < 0.000001)
        {
            ans.push_back("YES");
        }
        else
        {
            ans.push_back("NO");
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}