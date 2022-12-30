#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> test;
    vector<string> result;
    vector<string> ans;
    for (int i = 0; i < 6; i++)
    {
        string testword;
        getline(cin, testword);
        test.push_back(testword);
    }
    for (int i = 0; i < 6; i++)
    {
        string resultword;
        getline(cin, resultword);
        result.push_back(resultword);
    }
    string word;
    while (getline(cin, word))
    {
        bool isAns = true;
        for (int i = 0; i < 6; i++)
        {
            string outword;
            string temp = test[i];
            for (int k = 0; k < 5; k++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (word[j] == temp[k])
                    {
                        if (j == k)
                        {
                            outword.push_back('G');
                            temp[k] = '0';
                        }
                        else
                        {
                            outword.push_back('Y');
                        }
                        break;
                    }
                }
                if (outword[k] != 'G' && outword[k] != 'Y')
                {
                    outword.push_back('_');
                }
            }
            if (outword != result[i])
            {
                isAns = false;
                break;
            }
        }
        if (isAns)
        {
            ans.push_back(word);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}