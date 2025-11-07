#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MaxVolume(int d, int p, vector<int>& v, vector<vector<int>>& dp)
{
    int n = v.size(), m = dp[0].size() - 1;
    if (d == n) return p;
    if (dp[d][p] != -1) return dp[d][p];

    dp[d][p] = -2;
    if (p - v[d] >= 0)
        dp[d][p] = MaxVolume(d + 1, p - v[d], v, dp);
    if (p + v[d] <= m)
        dp[d][p] = max(dp[d][p], MaxVolume(d + 1, p + v[d], v, dp));
    return dp[d][p];
}

int main()
{
    FastIO;

    int n, s, m;
    cin >> n >> s >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<vector<int>> dp(n, vector<int>(m + 1, -1));
    int result = MaxVolume(0, s, v, dp);
    if (result == -2)
        cout << -1 << '\n';
    else
        cout << result << '\n';
}