#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n, l1, l2, s1, s2;
        cin >> n >> l1 >> l2 >> s1 >> s2;

        vector<vector<int>> v(4, vector<int>(n));
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < n - 1; j++)
                cin >> v[i][j];
        }

        array<int, 2> dp = { l1,l2 }, temp;
        for (int i = 0; i < n - 1; i++)
        {
            temp[0] = min(dp[0] + v[1][i], dp[1] + v[2][i]);
            temp[1] = min(dp[1] + v[3][i], dp[0] + v[0][i]);
            dp = temp;
        }

        int result = min(dp[0] + s1, dp[1] + s2);
        cout << result << '\n';
    }
}