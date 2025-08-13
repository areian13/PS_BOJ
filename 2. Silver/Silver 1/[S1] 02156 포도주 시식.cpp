#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MaxWine(int d, int k, vector<int>& wine, vector<vector<int>>& dp)
{
    int n = wine.size();

    if (d >= n)
        return 0;
    if (dp[d][k] != -1)
        return dp[d][k];

    static vector<vector<int>> graph = { {0,1},{2,3},{0,1},{2} };

    int result = 0;
    for (int nk : graph[k])
        result = max(result, wine[d] * (nk & 1) + MaxWine(d + 1, nk, wine, dp));
    return dp[d][k] = result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> wine(n);
    for (int i = 0; i < n; i++)
        cin >> wine[i];

    vector<vector<int>> dp(n, vector<int>(4, -1));
    int result = MaxWine(0, 0, wine, dp);
    cout << result << '\n';
}