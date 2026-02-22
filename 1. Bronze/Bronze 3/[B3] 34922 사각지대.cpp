#include <iostream>
#include <cstdio>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const double PI = acos(-1);

int main()
{
    FastIO;

    int w, h, r;
    cin >> w >> h >> r;

    double result = w * h - (PI * r * r / 4);
    printf("%.2lf\n", result);
}