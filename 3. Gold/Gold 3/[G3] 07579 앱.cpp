#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct App
{
    int m, c;
};

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<App> app(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> app[i].m;

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> app[i].c;
        sum += app[i].c;
    }

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - app[i].c >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - app[i].c] + app[i].m);
        }
    }

    for (int i = 0; i <= sum; i++)
    {
        if (dp[n][i] >= m)
        {
            cout << i << '\n';
            break;
        }
    }
}