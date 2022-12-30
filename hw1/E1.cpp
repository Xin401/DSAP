#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string word;
    getline(cin, word);
    vector<string> out;
    string ans;
    while (cin >> ans)
    {
        string temp = word;
        string outword;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (ans[i] == temp[j])
                {
                    if (i == j)
                    {
                        outword.push_back('G');
                        temp[j] = '0';
                    }
                    else
                    {
                        outword.push_back('Y');
                    }
                    break;
                }
            }
            if (outword[i] != 'G' && outword[i] != 'Y')
            {
                outword.push_back('_');
            }
        }
        out.push_back(outword);
    }
    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << endl;
    }
}