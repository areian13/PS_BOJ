#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 2> dr = { 0,1 };
array<int, 2> dc = { 1,0 };

long long CountRoute(int r, int c, vector<vector<int>>& map)
{
    int n = map.size();
    static vector<vector<long long>> dp(n, vector<long long>(n, -1));

    if (dp[r][c] != -1)
        return dp[r][c];
    if (r == n - 1 && c == n - 1)
        return dp[r][c] = 1;

    dp[r][c] = 0;
    for (int i = 0; i < 2; i++)
    {
        int nr = r + dr[i] * map[r][c];
        int nc = c + dc[i] * map[r][c];

        if (nr >= n || nc >= n)
            continue;

        dp[r][c] += CountRoute(nr, nc, map);
    }
    return dp[r][c];
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }

    long long result = CountRoute(0, 0, map);
    cout << result << '\n';
}