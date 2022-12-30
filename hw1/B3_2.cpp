#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool mysort(int a, int b)
{
    return a > b;
}
class Student
{
private:
    int score;
    string number;

public:
    void setScore(int a);
    void setNumber(string num);
    string getNumber();
    int getScore();
};
void Student::setScore(int a)
{
    score = a;
}
void Student::setNumber(string num)
{
    number = num;
}
string Student::getNumber()
{
    return number;
}
int Student::getScore()
{
    return score;
}
int main()
{
    int number = 0;
    int score;
    cin >> number;
    string stuNumber;
    vector<Student> student;
    while (cin >> score)
    {
        bool isExist = false;
        int existNum = 0;
        cin.ignore();
        getline(cin, stuNumber);
        Student stu;
        stu.setScore(score);
        stu.setNumber(stuNumber);
        if (student.size() != 0)
        {
            for (int i = 0; i < student.size(); i++)
            {
                // find if exist
                if (stu.getNumber() == student[i].getNumber())
                {
                    isExist = true;
                    existNum = i;
                    break;
                }
            }
            if (isExist)
            {
                if (student[existNum].getScore() < score)
                    student[existNum].setScore(score);
            }
            else
            {
                student.push_back(stu);
            }
        }
        else
        {
            student.push_back(stu);
        }
        if (student.size() >= number)
        {
            for (int i = 0; i < student.size() - 1; i++)
            {
                for (int j = 0; j < student.size() - 1 - i; j++)
                {
                    if (student[j].getScore() < student[j + 1].getScore())
                    {
                        swap(student[j], student[j + 1]);
                    }
                }
            }
        }
        if (student.size() > 0)
        {
            student.erase(student.end());
        }
    }

    for (int i = 0; i < (number > student.size() ? student.size() : number); i++)
    {
        cout << student[i].getNumber() << endl;
    }
}