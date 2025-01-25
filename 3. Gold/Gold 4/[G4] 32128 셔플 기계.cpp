#include <iostream>
#include <vector>
#include <array>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX_Y 1e+9
#define MAX_LOG2_Y 30

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<array<int, MAX_LOG2_Y>>> s(m, vector<array<int, MAX_LOG2_Y>>(n + 1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> s[i][j][0];
    }

    for (int i = 0; i < m; i++)
    {
        vector<array<int, MAX_LOG2_Y>>& temp = s[i];
        for (int j = 1; j < MAX_LOG2_Y; j++)
        {
            for (int k = 1; k <= n; k++)
                temp[k][j] = temp[temp[k][j - 1]][j - 1];
        }
    }

    vector<int> result(n + 1);
    for (int i = 1; i <= n; i++)
        result[i] = i;

    for (int q = 0; q < k; q++)
    {
        int x, y;
        cin >> x >> y;
        x--;

        vector<int> temp = result;
        for (int i = 1; i <= n; i++)
        {
            int d = y;
            int p = i;
            for (int j = 0; j < MAX_LOG2_Y; j++)
            {
                if (d & 1 << j)
                {
                    p = s[x][p][j];
                    d -= 1 << j;
                }
            }
            temp[p] = result[i];
        }

        for (int i = 1; i <= n; i++)
            result[i] = temp[i];
    }

    for (int i = 1; i <= n; i++)
        cout << result[i] << ' ';
    cout << '\n';
}