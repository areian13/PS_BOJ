#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 1'000;
const int MOD = 1'000'000'009;

int Sum123(int n, int m)
{
    static vector<vector<int>> dp(MAX + 1, vector<int>(MAX + 1, -1));
    if (n == 0) return (m == 0);
    if (m == 1) return (n <= 3 ? 1 : 0);
    if (dp[n][m] != -1) return dp[n][m];

    dp[n][m] = 0;
    for (int i = 3; i >= 1; i--)
    {
        if (i > n) continue;
        dp[n][m] += Sum123(n - i, m - 1);
        dp[n][m] %= MOD;
    }
    return dp[n][m];
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n, m;
        cin >> n >> m;

        int result = Sum123(n, m);
        cout << result << '\n';
    }
}