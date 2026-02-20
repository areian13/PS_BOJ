#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

vector<int> dr = { 0,1,-1 };
vector<int> dc = { 2,1,1 };

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m * 2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j * 2 + (i & 1)];
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int c = j * 2 + (i & 1);
            for (int k = 0; k < 3; k++)
            {
                int nr = i + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= n || nc >= m * 2)
                    continue;

                result += (grid[nr][nc] != grid[i][c]);
            }
        }
    }
    cout << result << '\n';
}