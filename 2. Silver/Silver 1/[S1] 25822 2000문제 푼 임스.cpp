#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;


int main()
{
    FastIO;

    double c;
    int n;
    cin >> c >> n;

    int maxS = 0;
    vector<bool> solved(n);
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;

        maxS = max(maxS, s);
        solved[i] = !!s;
    }

    int l = min((int)(c / 0.99), 2);
    vector<vector<int>> dp(n, vector<int>(l + 1, 0));
    dp[0][0] = solved[0];
    if (!solved[0] && l > 0)
        dp[0][1] = 1;

    for (int i = 1; i < n; i++)
    {
        if (solved[i])
        {
            for (int j = 0; j <= l; j++)
                dp[i][j] = dp[i - 1][j] + 1;
        }
        else
        {
            for (int j = 1; j <= l; j++)
                dp[i][j] = dp[i - 1][j - 1] + 1;
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= l; j++)
            result = max(result, dp[i][j]);
    }
    cout << result << '\n' << maxS << '\n';
}