#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> isHeavier(n, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        isHeavier[a][b] = true;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                isHeavier[i][j] = isHeavier[i][j] || (isHeavier[i][k] && isHeavier[k][j]);
        }
    }

    vector<vector<int>> cnt(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            cnt[i][0] += isHeavier[i][j];
            cnt[j][1] += isHeavier[i][j];
        }
    }

    int k = (n + 1) / 2;
    int result = 0;
    for (int i = 0; i < n; i++)
        result += (cnt[i][0] >= k || cnt[i][1] >= k);
    cout << result << '\n';
}