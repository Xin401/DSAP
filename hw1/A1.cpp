#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cin >> N;
    double *score = new double[N];
    double rate, bonus;
    cin >> rate >> bonus;
    for (int i = 0; i < N; i++)
    {
        cin >> score[i];
        score[i] *= rate;
        score[i] += bonus;
        score[i] = round(score[i]);
        score[i] = score[i] > 100 ? 100 : score[i];
        score[i] = score[i] < 0 ? 0 : score[i];
    }
    for (int i = 0; i < N; i++)
    {
        cout << score[i] << endl;
    }
    delete[] score;
}