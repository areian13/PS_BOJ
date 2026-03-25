#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int x, y, z, n;
    cin >> x >> y >> z >> n;

    double k = 1. * x / n;
    for (int i = 0; i < n; i++)
        printf("%.8lf 0 0 %.8lf %d %d \n", k * i, k * (i + 1), y, z);
}