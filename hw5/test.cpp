#include <iostream>
#include <string>
using namespace std;

int main()
{
    string formula;
    cin >> formula;
    size_t english = formula.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    size_t op = formula.find_first_of("+-*/<>");
    string num = formula.substr(english + 1, op - english - 1);
    size_t secenglish = formula.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ", english + 1);
    string num2 = formula.substr(secenglish + 1);
    cout << "";
}