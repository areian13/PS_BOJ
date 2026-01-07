#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MOD = 1'000'000'007;

int Bridge(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp)
{
    int m = grid[0].size();

    if (r == 0) return 1;
    if (dp[r][c] != -1) return dp[r][c];

    dp[r][c] = 0;
    for (int dc : { +1,0,-1 })
    {
        int nc = c + dc;
        if (nc < 0 || nc >= m)
            continue;
        if (grid[r - 1][nc] == 0)
            continue;
        dp[r][c] += Bridge(r - 1, nc, grid, dp);
        dp[r][c] %= MOD;
    }
    return dp[r][c];
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    vector<vector<int>> dp(n, vector<int>(m, -1));
    int result = 0;
    for (int j = 0; j < m; j++)
    {
        if (grid[n - 1][j] == 0)
            continue;
        result += Bridge(n - 1, j, grid, dp);
        result %= MOD;
    }
    cout << result << '\n';
}