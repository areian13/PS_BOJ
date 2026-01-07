#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MOD = 1'000'000'007;

int Meal(int t, int d, vector<vector<int>>& dp)
{
    int n = dp[0].size();
    if (d == n - 1) return 1;
    int& result = dp[t][d];
    if (result != -1) return result;

    result = 0;
    if (t == 0)
    {
        for (int i = 1; i <= 4; i++)
        {
            result += Meal(i, d + 1, dp);
            result %= MOD;
        }
    }
    else
    {
        result = Meal(0, d + 1, dp);
        for (int i = 1; i <= 4; i++)
        {
            if (abs(t - i) <= 1)
                continue;
            result += Meal(i, d + 1, dp);
            result %= MOD;
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> dp(5, vector<int>(n, -1));
    int result = 0;
    for (int i = 0; i < 5; i++)
    {
        result += Meal(i, 0, dp);
        result %= MOD;
    }
    cout << result << '\n';
}