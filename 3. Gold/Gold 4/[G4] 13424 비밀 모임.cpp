#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int ProximateRoom(vector<int>& pos, vector<vector<int>>& matrix)
{
    int n = matrix.size();

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    matrix[i][i] = 0;
                    continue;
                }
                if (matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
                    continue;

                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    int minValue = INT_MAX;
    int result = -1;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int x : pos)
            sum += matrix[x][i];

        if (sum < minValue)
        {
            minValue = sum;
            result = i;
        }
    }
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> matrix(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < m; i++)
        {
            int u, v, d;
            cin >> u >> v >> d;
            u--, v--;

            matrix[u][v] = d;
            matrix[v][u] = d;
        }

        int k;
        cin >> k;

        vector<int> pos(k);
        for (int i = 0; i < k; i++)
        {
            cin >> pos[i];
            pos[i]--;
        }

        int result = ProximateRoom(pos, matrix);
        cout << result + 1 << '\n';
    }
}