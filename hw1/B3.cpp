#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

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
    while (cin >> score && student.size() < number)
    {
        bool isExist = false;
        int existNum = 0;
        int rank = -1;
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
                stu.setScore(score > student[existNum].getScore() ? score : student[existNum].getScore());
                student.erase(student.begin() + existNum);
            }
            for (int i = 0; i < student.size(); i++)
            {
                // find his rank
                if (stu.getScore() > student[i].getScore())
                {
                    rank = i;
                    break;
                }
            }
            if (rank != -1)
            {
                student.insert(student.begin() + rank, stu);
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
        if (student.size() > number)
        {
            student.erase(student.end());
        }
    }
    if (number != 0)
    {
        for (int i = 0; i < (number > student.size() ? student.size() : number); i++)
        {
            cout << student[i].getNumber() << endl;
        }
    }
}