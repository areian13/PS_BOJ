#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MaxVolume(int d, int s, vector<int>& v, vector<vector<int>>& dp)
{
    int n = dp.size();
    int m = dp[0].size();

    if (s >= m || s < 0)
        return -1;
    if (d == n)
        return s;
    if (dp[d][s] != -2)
        return dp[d][s];

    int p = MaxVolume(d + 1, s + v[d], v, dp);
    int q = MaxVolume(d + 1, s - v[d], v, dp);
    return dp[d][s] = max(p, q);
}

int main()
{
    FastIO;

    int n, s, m;
    cin >> n >> s >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<vector<int>> dp(n, vector<int>(m + 1, -2));
    int result = MaxVolume(0, s, v, dp);
    cout << result << '\n';
}