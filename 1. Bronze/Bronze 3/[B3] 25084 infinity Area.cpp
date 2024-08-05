#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define PI 3.14159265359

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        long long r, a, b;
        cin >> r >> a >> b;

        long long sum = r * r;
        bool isLeft = true;
        while (r > 0)
        {
            r = (isLeft ? r * a : r / b);
            sum += r * r;

            isLeft = !isLeft;
        }

        double result = PI * sum;
        printf("Case #%d: %.6lf\n", t, result);
    }
}