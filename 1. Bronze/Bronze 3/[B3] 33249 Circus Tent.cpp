#include <iostream>
#include <cstdio>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const double PI = acos(-1);

int main()
{
    FastIO;

    double d, h;
    cin >> d >> h;
    
    double r = d / 2 + 5;
    double result = PI * r * 2 * h + PI * r * r;
    printf("%.6lf\n", result);
}