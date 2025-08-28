#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MinFuel(int d, int j, int p, vector<vector<int>>& map,
    vector<vector<vector<int>>>& dp)
{
    int n = map.size();
    int m = map[0].size();

    if (d == n - 1)
        return map[d][j];
    if (dp[p][d][j] != -1)
        return dp[p][d][j];

    int result = INT_MAX;
    for (int i = 0; i < 3; i++)
    {
        if (i == p)
            continue;
        int nj = j + (i - 1);
        if (nj < 0 || nj >= m)
            continue;

        result = min(result, MinFuel(d + 1, nj, i, map, dp));
    }
    return dp[p][d][j] = result + map[d][j];
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

    vector dp(4, vector(n, vector<int>(m, -1)));
    int result = INT_MAX;
    for (int j = 0; j < m; j++)
        result = min(result, MinFuel(0, j, 3, map, dp));
    cout << result << '\n';
}