#include <iostream>
#include <cmath>
using namespace std;

float angle(float x1, float x2, float y1, float y2);
int main()
{
    cout << angle(40, 0, 40, 0);
}

float angle(float x1, float x2, float y1, float y2)
{
    float ang;
    float xx, yy;
    xx = x2 - x1;
    yy = y2 - y1;
    ang = atan2(yy, xx);
    ang = ang / M_PI * 180;
    if (ang < 0)
    {
        ang += 360;
    }
    return ang;
};