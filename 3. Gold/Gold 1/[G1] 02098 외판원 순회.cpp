#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define INF INT_MAX

int TSP(int u, int isVisited, vector<vector<int>>& w,
    vector<vector<int>>& dp)
{
    int n = w.size();
    int& result = dp[u][isVisited];

    if (result != -1)
        return dp[u][isVisited];
    if (isVisited == (1 << n) - 1)
        return w[u][0] != 0 ? w[u][0] : INF;

    result = INF;
    for (int v = 0; v < n; v++)
    {
        if (w[u][v] == 0 || isVisited & (1 << v))
            continue;

        int d = TSP(v, isVisited | (1 << v), w, dp);
        if (d == INF)
            continue;
        result = min(result, d + w[u][v]);
    }

    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> w(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> w[i][j];
    }

    vector<vector<int>> dp(n, vector<int>(1 << n, -1));
    int result = TSP(0, 1, w, dp);
    cout << result << '\n';
}