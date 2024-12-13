#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> preSum(n, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int t;
            cin >> t;

            preSum[i][j + 1] = preSum[i][j] + t;
        }
    }

    vector<int> result(m, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int cntL = 0;
            int cntR = 0;
            for (int k = 0; k < n; k++)
            {
                cntL += (preSum[k][i] <= preSum[j][i] && preSum[j][i] < preSum[k][i + 1]);
                cntR += (preSum[k][i] <= preSum[j][i + 1] && preSum[j][i + 1] < preSum[k][i + 1]);
            }
            result[i] = max({ result[i],cntL,cntR });
        }
        cout << result[i] << ' ';
    }
    cout << '\n';
}