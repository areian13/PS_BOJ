#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

int DP(int d, int k, vector<vector<int>>& map, vector<vector<int>>& dp)
{
    int n = map.size();
    if (d == n - 1) return map[d][k];
    if (dp[d][k] != -INF) return dp[d][k];

    for (int dk : {-1, 0, +1})
    {
        int nk = k + dk;
        if (nk < 0 || nk >= 3)
            continue;
        dp[d][k] = max(dp[d][k], DP(d + 1, nk, map, dp) + map[d][k]);
    }
    return dp[d][k];
}

int MaxScore(vector<vector<int>>& map)
{
    int n = map.size();
    vector<vector<int>> dp(n, vector<int>(3, -INF));
    int result = -INF;
    for (int i = 0; i < 3; i++)
        result = max(result, DP(0, i, map, dp));
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> map[i][j];
    }

    cout<< MaxScore(map) <<' ';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
            map[i][j] *= -1;
    }
    cout << -MaxScore(map) << '\n';
}