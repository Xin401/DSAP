#include <iostream>
#include <algorithm>
using namespace std;

class PocketCube
{
public:
    PocketCube()
    {
        int i = 0;
        for (i; i < 3; i++)
        {
            Color[i] = 'W';
        }
        for (i; i < 6; i++)
        {
            Color[i] = 'O';
        }
        for (i; i < 10; i++)
        {
            Color[i] = 'G';
        }
        for (i; i < 14; i++)
        {
            Color[i] = 'R';
        }
        for (i; i < 17; i++)
        {
            Color[i] = 'B';
        }
        for (i; i < 21; i++)
        {
            Color[i] = 'Y';
        }
    }
    PocketCube RotateFront();
    PocketCube RotateRight();
    PocketCube RotateDown();
    char Color[21];

private:
};

void mySwap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

PocketCube PocketCube::RotateFront()
{
    mySwap(&Color[1], &Color[10]);
    mySwap(&Color[1], &Color[3]);
    mySwap(&Color[3], &Color[17]);
    mySwap(&Color[2], &Color[12]);
    mySwap(&Color[2], &Color[5]);
    mySwap(&Color[5], &Color[18]);
    mySwap(&Color[6], &Color[7]);
    mySwap(&Color[6], &Color[8]);
    mySwap(&Color[8], &Color[9]);
    return *this;
}

PocketCube PocketCube::RotateRight()
{
    mySwap(&Color[0], &Color[15]);
    mySwap(&Color[0], &Color[7]);
    mySwap(&Color[7], &Color[18]);

    mySwap(&Color[2], &Color[14]);
    mySwap(&Color[2], &Color[9]);
    mySwap(&Color[9], &Color[20]);

    mySwap(&Color[10], &Color[11]);
    mySwap(&Color[10], &Color[12]);
    mySwap(&Color[12], &Color[13]);
    return *this;
}

PocketCube PocketCube::RotateDown()
{
    mySwap(&Color[4], &Color[8]);
    mySwap(&Color[4], &Color[15]);
    mySwap(&Color[12], &Color[15]);

    mySwap(&Color[5], &Color[9]);
    mySwap(&Color[5], &Color[16]);
    mySwap(&Color[13], &Color[16]);

    mySwap(&Color[17], &Color[18]);
    mySwap(&Color[17], &Color[19]);
    mySwap(&Color[19], &Color[20]);
    return *this;
}

std::ostream &operator<<(std::ostream &os, const PocketCube &cube)
{
    os << "--" << 'W' << cube.Color[0] << "----" << '\n';

    os << "--" << cube.Color[1] << cube.Color[2] << "----" << '\n';

    os << 'O' << cube.Color[3] << cube.Color[6] << cube.Color[7] << cube.Color[10] << cube.Color[11] << cube.Color[14] << 'B' << '\n';

    os << cube.Color[4] << cube.Color[5] << cube.Color[8] << cube.Color[9] << cube.Color[12] << cube.Color[13] << cube.Color[15] << cube.Color[16] << '\n';

    os << "--" << cube.Color[17] << cube.Color[18] << "----" << '\n';

    os << "--" << cube.Color[19] << cube.Color[20] << "----" << '\n';
    return os;
}

#include <iostream>
#include <random> // For Test
#include <vector> // For Test

void Test1(); // Sample1
void Test2(); // All
void Test3(); // RotateRight, RotateDown
void Test4(); // 重複其中一種旋轉
void Test5(); // 同時有多個
void Test6(); // All
void Test7(); // RotateRight, RotateDown
void Test8(); // 重複其中一種旋轉
void Test9(); // 同時有多個

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int id;
    std::cin >> id;
    void (*f[])() = {Test1, Test2, Test3, Test4, Test5, Test6, Test7, Test8, Test9};
    f[id - 1]();
}

void Test1()
{
    PocketCube a, b, c, d;

    std::cout << a << std::endl;
    std::cout << a.RotateFront() << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;
    std::cout << b.RotateDown() << std::endl;
    std::cout << b << std::endl;

    std::cout << c << std::endl;
    std::cout << c.RotateRight() << std::endl;
    std::cout << c << std::endl;

    std::cout << d.RotateFront().RotateRight().RotateDown().RotateRight() << std::endl;
    std::cout << PocketCube().RotateFront().RotateFront().RotateFront().RotateFront() << std::endl;
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
void Test8()
{ /* HIDDEN */
}
void Test9()
{ /* HIDDEN */
}