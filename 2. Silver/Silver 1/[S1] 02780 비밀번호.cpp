#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 1'000
#define MOD 1'234'567
vector<vector<int>> dp(MAX + 1, vector<int>(10, -1));
vector<vector<int>> graph = {
    {7}, {2,4}, {1,3,5}, {2,6}, {1,5,7}, {2,4,6,8},
    {3,5,9}, {4,8,0}, {5,7,9}, {6,8}
};

int Lock(int n, int d)
{
    if (n == 1) return 1;
    if (dp[n][d] != -1) return dp[n][d];

    dp[n][d] = 0;
    for (int u : graph[d])
        dp[n][d] += Lock(n - 1, u), dp[n][d] %= MOD;
    return dp[n][d];
}
int Lock(int n)
{
    int result = 0;
    for (int i = 0; i < 10; i++)
        result += Lock(n, i), result %= MOD;
    return result;
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

        int result = Lock(n);
        cout << result << '\n';
    }
}