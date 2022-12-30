#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> three;
    int a;
    while (cin >> a && three.size() < 3)
    {
        three.push_back(a);
    }
    sort(three.begin(), three.end());
    while (cin >> a && three.size() == 3)
    {
        if (a >= three[2])
        {
            three[0] = three[1];
            three[1] = three[2];
            three[2] = a;
            continue;
        }
        if (a >= three[1])
        {
            three[0] = three[1];
            three[1] = a;
            continue;
        }
        if (a >= three[0])
        {
            three[0] = a;
        }
    }
    sort(three.begin(), three.end());
    three.size() == 3 ? cout << three[0] : cout << three[0];
}