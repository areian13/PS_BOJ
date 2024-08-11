#include <iostream>
#include <cstdio>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        double a, b, c;
        cin >> a >> b >> c;

        double x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        double x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

        printf("%.3lf, %.3lf\n", x1, x2);
    }
}