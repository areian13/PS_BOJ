#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

vector<int> dr = { 0,1,0,-1 };
vector<int> dc = { 1,0,-1,0 };

bool IsCircle(vector<vector<char>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'X')
                continue;

            int cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                int nr = i + dr[k];
                int nc = j + dc[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                cnt += (grid[nr][nc] == '.');
            }

            if (cnt <= 1)
                return false;
        }
    }
    return true;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    bool result = IsCircle(grid);
    cout << !result << '\n';
}