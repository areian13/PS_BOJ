#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define EPS 1e-9
typedef long double ld;

ld f(ld x, ld a, ld b, ld c)
{
    return a * x + b * sin(x) - c;
}
ld fp(ld a, ld b, ld c)
{
    ld start = 0, end = a + b + c;
    while ((end - start) > EPS)
    {
        ld mid = (start + end) / 2;
        ld fx = f(mid, a, b, c);

        if (abs(fx) < EPS)
            return mid;
        if (fx < 0)
            start = mid;
        else if (fx > 0)
            end = mid;
    }
}

int main()
{
    FastIO;

    ld a, b, c;
    cin >> a >> b >> c;

    ld result = fp(a, b, c);
    printf("%.9llf\n", result);
}