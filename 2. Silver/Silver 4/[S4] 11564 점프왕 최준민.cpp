#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long k, a, b;
    cin >> k >> a >> b;

    if (a < 0 && b < 0)
        a *= -1, b *= -1, swap(a, b);

    if (a <= 0 && b >= 0)
        cout << -a / k + b / k + 1 << '\n';
    else
        cout << b / k - (a - 1) / k << '\n';
}