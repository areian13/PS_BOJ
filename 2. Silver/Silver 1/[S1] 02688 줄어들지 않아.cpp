#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 64

long long DP(int n, int d)
{
    static vector<vector<long long>> dp(MAX + 1, vector<long long>(10, -1));
    if (n == 0) return 1;
    if (dp[n][d] != -1) return dp[n][d];

    dp[n][d] = 0;
    for (int i = 0; i <= d; i++)
        dp[n][d] += DP(n - 1, i);
    return dp[n][d];
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        long long result = DP(n, 9);
        cout << result << '\n';
    }
}