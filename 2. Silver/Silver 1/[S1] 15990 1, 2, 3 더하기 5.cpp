#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 100'000;
const int MOD = 1'000'000'009;

int Sum123(int n, int k)
{
    static vector<vector<int>> dp(MAX + 1, vector<int>(5, -1));
    if (n == 0) return 1;
    if (dp[n][k] != -1) return dp[n][k];

    dp[n][k] = 0;
    for (int nk : {3, 2, 1})
    {
        if (nk > n || nk == k) continue;
        dp[n][k] += Sum123(n - nk, nk);
        dp[n][k] %= MOD;
    }
    return dp[n][k];
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        int result = Sum123(n, 4);
        cout << result << '\n';
    }
}