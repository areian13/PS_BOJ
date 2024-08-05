#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

int A(int x)
{
    x /= 1'000;

    if (x <= 5)
        return 400;
    if (x <= 10)
        return 700;
    if (x <= 20)
        return 1'200;
    if (x <= 30)
        return 1'700;
    return x * 57;
}

int B(int x)
{
    x /= 1'000;

    if (x <= 2)
        return 90 + x * 90;
    if (x <= 5)
        return 100 + x * 85;
    if (x <= 20)
        return 125 + x * 80;
    if (x <= 40)
        return 325 + x * 70;
    return 925 + x * 55;
}

int main()
{
    FastIO;

    int x1, x2;
    cin >> x1 >> x2;

    lf(2);
    float result = (min(A(x1), B(x1)) + min(A(x2), B(x2))) / 100.0;
    cout << result << '\n';
}