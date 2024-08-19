#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int m, n;
    cin >> m >> n;

    vector<vector<int>> preSum(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int p;
            cin >> p;

            preSum[i][j] = p + preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1];
        }
    }

    int result = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = i; k >= 0; k--)
            {
                for (int l = j; l >= 0; l--)
                {
                    int sum = preSum[i][j] - preSum[i][l] - preSum[k][j] + preSum[k][l];
                    if (sum > 10)
                        break;

                    result += (sum == 10);
                }
            }
        }
    }
    cout << result << '\n';
}