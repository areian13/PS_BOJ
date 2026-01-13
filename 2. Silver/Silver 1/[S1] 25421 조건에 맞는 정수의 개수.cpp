#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MOD = 987'654'321;

int Gap2(int d, int v, vector<vector<int>>& dp)
{
    int n = dp[0].size();
    if (d == n - 1) return 1;
    int& result = dp[v][d];
    if (result != -1) return result;

    result = 0;
    for (int nv : {v - 2, v - 1, v, v + 1, v + 2})
    {
        if (nv < 1 || 9 < nv)
            continue;
        result += Gap2(d + 1, nv, dp);
        result %= MOD;
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> dp(10, vector<int>(n, -1));
    int result = 0;
    for (int i = 1; i < 10; i++)
    {
        result += Gap2(0, i, dp);
        result %= MOD;
    }
    cout << result << '\n';
}