#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 29

int main()
{
    FastIO;

    vector<vector<int>> dp(MAX + 1, vector<int>(MAX + 1, 1));
    for (int i = 1; i <= MAX; i++)
    {
        for (int j = 1; j <= i; j++)
            dp[i][j] = dp[i][j - 1] * (i - j + 1) / j;
    }

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        int result = dp[m][n];
        cout << result << '\n';
    }
}