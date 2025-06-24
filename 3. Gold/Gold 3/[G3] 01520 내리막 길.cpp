#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 4> dr = { 0,1,0,-1 };
array<int, 4> dc = { 1,0,-1,0 };

int DFS(int r, int c, vector<vector<int>>& map, vector<vector<int>>& dp)
{
    int n = map.size();
    int m = map[0].size();

    if (dp[r][c] != -1)
        return dp[r][c];
    if (r == n - 1 && c == m - 1)
        return dp[r][c] = 1;

    dp[r][c] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m)
            continue;
        if (dp[nr][nc] == 0 || map[r][c] <= map[nr][nc])
            continue;

        dp[r][c] += DFS(nr, nc, map, dp);
    }
    return dp[r][c];
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    vector<vector<int>> dp(n, vector<int>(m, -1));
    int result = DFS(0, 0, map, dp);
    cout << result << '\n';
}