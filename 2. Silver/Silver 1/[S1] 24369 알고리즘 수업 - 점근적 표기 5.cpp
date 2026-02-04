#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsPositive(int a2, int a1, int a0, int n0)
{
    if (a2 < 0) return false;

    long long p = 1LL * a1 * a1 - 4LL * a2 * a0;
    if (p <= 0) return true;
    long long r = 2LL * a2 * n0 + a1;
    return r >= 0 && p <= r * r;
}

int main()
{
    FastIO;

    int a2, a1, a0, c, n0;
    cin >> a2 >> a1 >> a0 >> c >> n0;

    bool result = IsPositive(a2 - c, a1, a0, n0);
    cout << result << '\n';
}