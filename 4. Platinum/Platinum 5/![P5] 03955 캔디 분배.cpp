#include <iostream>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

pair<int, int> xgcd(int a, int b)
{
    if (b == 0) return { 1,0 };
    auto [x, y] = xgcd(b, a % b);
    return { y, x - (a / b) * y };
}
int Inv(int a, int mod)
{
    if (gcd(a, mod) != 1) return -1;
    return (xgcd(a, mod).first + mod) % mod;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int k, c;
        cin >> k >> c;

        int result = Inv(k, c);
        if (result == -1) cout << "IMPOSSIBLE" << '\n';
        else cout << result << '\n';
    }
}