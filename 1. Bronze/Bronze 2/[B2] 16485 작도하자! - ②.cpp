#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int c, b;
    cin >> c >> b;

    double result = 1. * c / b;
    printf("%.6lf\n", result);
}