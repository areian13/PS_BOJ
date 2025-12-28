#include <iostream>
#include <string>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

int MinPalin(int d, vector<vector<bool>>& isPalin, vector<int>& dp)
{
    int n = dp.size();
    if (d == n) return 0;
    if (dp[d] != -1) return dp[d];

    dp[d] = INF;
    for (int i = d; i < n; i++)
    {
        if (!isPalin[d][i])
            continue;

        dp[d] = min(dp[d], MinPalin(i + 1, isPalin, dp) + 1);
    }
    return dp[d];
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    int n = s.size();
    vector<vector<bool>> isPalin(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
        isPalin[i][i] = true;

    for (int l = 2; l <= n; l++)
    {
        for (int i = 0, j = i + l - 1; j < n; i++, j++)
        {
            if (s[i] == s[j] && (l == 2 || isPalin[i + 1][j - 1]))
                isPalin[i][j] = true;
        }
    }

    vector<int> dp(n, -1);
    int result = MinPalin(0, isPalin, dp);
    cout << result << '\n';
}