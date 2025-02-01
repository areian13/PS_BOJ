#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, x;
    cin >> n >> x;

    double result = (n / ((n * (100 - x) / 100.0)) - 1) * 100;
    printf("%.6lf\n", result);
}