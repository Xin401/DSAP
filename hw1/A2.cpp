#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string judge(int s)
{
    if (s <= 100 && s >= 90)
        return "A+";
    if (s <= 89 && s >= 85)
        return "A";
    if (s <= 84 && s >= 80)
        return "A-";
    if (s <= 79 && s >= 77)
        return "B+";
    if (s <= 76 && s >= 73)
        return "B";
    if (s <= 72 && s >= 70)
        return "B-";
    if (s <= 69 && s >= 67)
        return "C+";
    if (s <= 66 && s >= 63)
        return "C";
    if (s <= 62 && s >= 60)
        return "C-";
    if (s <= 59)
        return "F";
}

int main()
{
    int N;
    cin >> N;
    double *score = new double[N];
    string *grade[2];
    for (int i = 0; i < 2; i++)
    {
        grade[i] = new string[N];
    }
    double rate, bonus;
    cin >> rate >> bonus;
    for (int i = 0; i < N; i++)
    {
        cin >> score[i];
        grade[0][i] = judge(score[i]);
        score[i] *= rate;
        score[i] += bonus;
        score[i] = round(score[i]);
        score[i] = score[i] > 100 ? 100 : score[i];
        score[i] = score[i] < 0 ? 0 : score[i];
        grade[1][i] = judge(score[i]);
    }
    for (int i = 0; i < N; i++)
    {
        cout << grade[0][i] << " -> " << grade[1][i] << endl;
    }
    delete[] score;
    for (int i = 0; i < 2; i++)
    {
        delete[] grade[i];
    }
}