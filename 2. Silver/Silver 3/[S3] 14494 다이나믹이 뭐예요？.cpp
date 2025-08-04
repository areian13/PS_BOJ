#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MOD 1'000'000'007

int Route(int r, int c, vector<vector<int>>& dp)
{
    if (dp[r][c] != -1)
        return dp[r][c];
    if (r == 1 || c == 1)
        return dp[r][c] = 1;

    int l = Route(r - 1, c, dp);
    int d = Route(r, c - 1, dp);
    int k = Route(r - 1, c - 1, dp);
    return dp[r][c] = ((l + d) % MOD + k) % MOD;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int result = Route(n, m, dp);
    cout << result << '\n';
}