#include <iostream>
#include <cstdio>
#include <vector>
#include <array>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = 1'000'000;
array<int, 4> dr = { 0,1,1,1 };
array<int, 4> dc = { 1,1,-1,0 };

int main()
{
    FastIO;

    int tc = 0;
    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        vector<vector<int>> map(n, vector<int>(3));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
                cin >> map[i][j];
        }

        vector<vector<int>> dp(n, vector<int>(3, INF));
        dp[0][1] = map[0][1];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int pre = INF;
                for (int k = 0; k < 4; k++)
                {
                    int nr = i - dr[k];
                    int nc = j - dc[k];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= 3)
                        continue;

                    pre = min(pre, dp[nr][nc]);
                }

                dp[i][j] = min(dp[i][j], pre + map[i][j]);
            }
        }
        printf("%d. %d\n", ++tc, dp[n - 1][1]);
    }
}