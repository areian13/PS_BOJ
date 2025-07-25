#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edge(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        edge[a][b] = 1;
    }
    for (int i = 0; i < n; i++)
        edge[i][i] = 0;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (edge[i][k] == INT_MAX || edge[k][j] == INT_MAX)
                    continue;

                edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
            }
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        bool isKnown = true;
        for (int j = 0; j < n; j++)
            isKnown &= (edge[i][j] != INT_MAX || edge[j][i] != INT_MAX);
        result += isKnown;
    }
    cout << result << '\n';
}