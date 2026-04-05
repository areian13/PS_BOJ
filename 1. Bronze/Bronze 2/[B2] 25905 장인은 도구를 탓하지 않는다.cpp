#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    vector<double> p(10);
    for (int i = 0; i < 10; i++)
        cin >> p[i];
    sort(p.begin(), p.end(), greater<double>());

    double result = p[0];
    for (int x = 1; x < 9; x++)
        result *= p[x] / (x + 1);
    printf("%6lf\n", result * 1e+9);
}