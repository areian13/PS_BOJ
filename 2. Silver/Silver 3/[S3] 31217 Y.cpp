#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MOD 1'000'000'007

int nCr(int n, int r, vector<vector<int>>& dp)
{
    if (n == r || r == 0)
        return dp[n][r] = 1;
    if (dp[n][r] != 0)
        return dp[n][r];

    return dp[n][r] = (nCr(n - 1, r - 1, dp) + nCr(n - 1, r, dp)) % MOD;
}

int CountY(vector<int>& cnt)
{
    int n = cnt.size();

    int result = 0;
    vector<vector<int>> dp(n + 1, vector<int>(4, 0));
    for (int i = 0; i < n; i++)
    {
        if (cnt[i] < 3)
            continue;

        result += nCr(cnt[i], 3, dp);
        result %= MOD;
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> cnt(n, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        cnt[u]++;
        cnt[v]++;
    }

    int result = CountY(cnt);
    cout << result << '\n';
}