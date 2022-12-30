#include <cmath>
#include <string>
#include <iostream>
#include <map>

// ans
using namespace std;

class Grade
{
public:
    Grade();
    Grade(int p);
    Grade(string r);
    Grade(const char *r);
    int GetScores() const;
    int GetComp() const;
    string GetRank() const;
    bool operator<(const Grade &rhs) const;
    bool operator>(const Grade &rhs) const;
    bool operator==(const Grade &rhs) const;
    bool operator!=(const Grade &rhs) const;
    void setScores(int p);
    void Reset();
    operator bool() const;

private:
    int point;
    int comp;
    string rank;
};

Grade Adjust(const Grade &g, int added);
void Grade::setScores(int p)
{
    point = p;
}
int Grade::GetComp() const
{
    return comp;
}
int Grade::GetScores() const
{
    return point;
}
string Grade::GetRank() const
{
    return rank;
}
Grade::Grade()
{
    point = 0;
    comp = 0;
    rank = "X";
}
Grade::Grade(int p)
{
    point = p;
    if (p <= 100 && p >= 90)
    {
        rank = "A+";
        comp = 9;
    }
    if (p <= 89 && p >= 85)
    {
        rank = "A";
        comp = 8;
    }
    if (p <= 84 && p >= 80)
    {
        rank = "A-";
        comp = 7;
    }
    if (p <= 79 && p >= 77)
    {
        rank = "B+";
        comp = 6;
    }
    if (p <= 76 && p >= 73)
    {
        rank = "B";
        comp = 5;
    }
    if (p <= 72 && p >= 70)
    {
        rank = "B-";
        comp = 4;
    }
    if (p <= 69 && p >= 67)
    {
        rank = "C+";
        comp = 3;
    }
    if (p <= 66 && p >= 63)
    {
        rank = "C";
        comp = 2;
    }
    if (p <= 62 && p >= 60)
    {
        rank = "C-";
        comp = 1;
    }
    if (p <= 59)
    {
        rank = "F";
        comp = 0;
    }
}
Grade::Grade(string r)
{
    rank = r;
    if (rank == "A+")
    {
        point = 95;
        comp = 9;
    }
    if (rank == "A")
    {
        point = 87;
        comp = 8;
    }
    if (rank == "A-")
    {
        point = 82;
        comp = 7;
    }
    if (rank == "B+")
    {
        point = 78;
        comp = 6;
    }
    if (rank == "B")
    {
        point = 75;
        comp = 5;
    }
    if (rank == "B-")
    {
        point = 70;
        comp = 4;
    }
    if (rank == "C+")
    {
        point = 68;
        comp = 3;
    }
    if (rank == "C")
    {
        point = 65;
        comp = 2;
    }
    if (rank == "C-")
    {
        point = 60;
        comp = 1;
    }
    if (rank == "F")
    {
        point = 50;
        comp = 0;
    }
    if (rank == "X")
    {
        point = 0;
        comp = 0;
    }
}
Grade::Grade(const char *r)
{
    string rankr = r;
    rank = rankr;
    if (rank == "A+")
    {
        point = 95;
        comp = 9;
    }
    if (rank == "A")
    {
        point = 87;
        comp = 8;
    }
    if (rank == "A-")
    {
        point = 82;
        comp = 7;
    }
    if (rank == "B+")
    {
        point = 78;
        comp = 6;
    }
    if (rank == "B")
    {
        point = 75;
        comp = 5;
    }
    if (rank == "B-")
    {
        point = 70;
        comp = 4;
    }
    if (rank == "C+")
    {
        point = 68;
        comp = 3;
    }
    if (rank == "C")
    {
        point = 65;
        comp = 2;
    }
    if (rank == "C-")
    {
        point = 60;
        comp = 1;
    }
    if (rank == "F")
    {
        point = 50;
        comp = 0;
    }
    if (rank == "X")
    {
        point = 0;
        comp = 0;
    }
}
ostream &operator<<(std::ostream &os, const Grade &a)
{
    os << a.GetRank();
    return os;
}
bool Grade::operator<(const Grade &rhs) const
{
    if (this->GetComp() < rhs.GetComp())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Grade::operator>(const Grade &rhs) const
{
    if (this->GetComp() > rhs.GetComp())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Grade::operator==(const Grade &rhs) const
{
    if (this->GetComp() == rhs.GetComp())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Grade::operator!=(const Grade &rhs) const
{
    if (this->GetComp() != rhs.GetComp())
    {
        return true;
    }
    else
    {
        return false;
    }
}
Grade Adjust(const Grade &g, int added)
{
    int newPoint = g.GetScores() + added;
    if (g.GetRank() != "X")
    {
        if (newPoint < 0)
        {
            newPoint = 0;
        }
        if (newPoint > 100)
        {
            newPoint = 100;
        }
        Grade temp(newPoint);
        return temp;
    }
    else
    {
        Grade temp("X");
        temp.setScores(newPoint);
        return temp;
    }
}
void Grade::Reset()
{
    rank = "X";
    point = 0;
    comp = 0;
}
Grade::operator bool() const
{
    if (this->GetRank() == "X")
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int id;
    std::cin >> id;
    void (*f[])() = {Test1, Test2, Test3, Test4, Test5, Test6, Test7};
    f[id - 1]();
}

void Test1()
{
    // Grade 可預設初始化為『未給分』
    {
        Grade g;
        std::cout << g << std::endl; // 此時印出 "X"
    }

    // Grade 可用 C 風格字串或 C++字串 (std::string) 表示等第成績後進行初始化或賦值
    {
        Grade g1 = "A";
        std::cout << g1 << std::endl; // 此時印出 "A"

        g1 = "B+";
        std::cout << g1 << std::endl; // 此時印出 "B+"

        Grade g2 = std::string("A+");
        std::cout << g2 << std::endl; // 此時印出 "A+"

        g2 = std::string("C");
        std::cout << g2 << std::endl; // 此時印出 "C"
    }

    // Grade 可用整數 (int) 表示百分制成績後進行初始化或賦值
    // - 如果輸入的整數超過百分制成績範圍 [0, 100] 的話是《未定義行為》(UB: Undefined Behavior)
    {
        Grade g = 100;
        std::cout << g << std::endl; // 此時印出 "A+"

        g = 75;
        std::cout << g << std::endl; // 此時印出 "B"
    }

    // Grade 物件提供 GetRank() 操作，回傳其等第字串 (std::string 型態)
    {
        const Grade g1 = "A";
        std::string g2 = g1.GetRank();
        std::cout << g2 << std::endl; // 印出 "A"
    }

    // Grade 物件提供 GetScores() 操作，回傳百分制分數 (int 型態)
    {
        const Grade g1 = "A";
        std::cout << g1.GetScores() << std::endl; // 此時印出 "87"

        const Grade g2 = 53;
        std::cout << g2.GetScores() << std::endl; // 此時印出 "53"

        const Grade g3 = "X";
        std::cout << g3.GetScores() << std::endl; // 此時印出 "0"
    }

    // Grade 物件可進行比較運算 (>, <, ==, !=)，回傳 bool 型態值
    // - 比較時，不管百分制分數高低，而只以等第高低比較：A+ > A > A- > B+ > B > B- > C+ > C > C- > F = X
    // - 比較時，同等第表示相等：A+ 與 A+ 相等，A+ 與 A 不相等
    // - 比較時，F 與 X 是相等的
    {
        const Grade g1 = "A", g2 = "A+", g3 = "B-", g4 = "B-", g5 = "F", g6 = "X";
        std::cout << std::boolalpha << (g3 == g4) << std::endl; // 印出 "true"
        std::cout << std::boolalpha << (g1 != g2) << std::endl; // 印出 "true"
        std::cout << std::boolalpha << (g1 < g2) << std::endl;  // 印出 "true"
        std::cout << std::boolalpha << (g1 > g2) << std::endl;  // 印出 "false"
        std::cout << std::boolalpha << (g5 == g6) << std::endl; // 印出 "true"
        std::cout << std::boolalpha << (g4 > g5) << std::endl;  // 印出 "true"
        std::cout << std::boolalpha << (g6 < g2) << std::endl;  // 印出 "true"
    }

    // 提供 Adjust(const Grade g, int added) 函式回傳依照百分制調分後的成績 (Grade 型態)
    // - 調分結果是用原本百分制分數加上 added 之後的成績
    // - added 的整數值需要在 [-100, 100] 之間，否則為《未定義行為》(UB: Undefined Behavior)
    // - 調分後如果超過 100 以 100 計、低於 0 以 0 計
    // - g 如果原本是未給分 ("X")，調分為依舊需要是未給分 ("X")
    {
        Grade g1 = 85;
        std::cout << Adjust(g1, 10) << std::endl;             // 印出 "A+"
        std::cout << g1 << std::endl;                         // 印出 "A"
        std::cout << Adjust(g1, 10).GetScores() << std::endl; // 印出 "95"
        std::cout << Adjust(g1, 20).GetScores() << std::endl; // 印出 "100"

        Grade g2;
        std::cout << Adjust(g2, 10) << std::endl; // 印出 "X"
    }

    // Grade 物件提供 Reset() 操作，將成績轉成未給分 ("X")
    {
        Grade g = "A+";
        g.Reset();
        std::cout << g << std ::endl; // 此時印出 "X"
    }

    // Grade 物件可隱性轉型成 bool 型態，表示是否已經給分**
    {
        const Grade g1 = "A+";
        bool isG1Graded = g1;
        std::cout << std::boolalpha << isG1Graded << std::endl; // 此時印出 "true"

        const Grade g2;
        bool isG2Graded = g2;
        std::cout << std::boolalpha << isG2Graded << std::endl; // 此時印出 "false"

        if (g1)
        {
            std::cout << "g1" << std::endl; // 印出 "g1"
        }

        if (g2)
        {
            std::cout << "g2" << std::endl; // 不會執行到
        }
    }
}

void Test2()
{ /* HIDDEN */
}
void Test3()
{ /* HIDDEN */
}
void Test4()
{ /* HIDDEN */
}
void Test5()
{ /* HIDDEN */
}
void Test6()
{ /* HIDDEN */
}
void Test7()
{ /* HIDDEN */
}