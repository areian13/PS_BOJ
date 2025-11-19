#include <iostream>
#include <vector>
#include <climits>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

struct Pos
{
    int r, c;
};

array<int, 2> dr = { 0,1 };
array<int, 2> dc = { 1,0 };

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }

    vector<vector<bool>> visit(n, vector<bool>(n, false));
    visit[0][0] = true;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (r == n - 1 && c == n - 1)
                continue;
            if (!visit[r][c])
                continue;

            for (int i = 0; i < 2; i++)
            {
                int nr = r + dr[i] * grid[r][c];
                int nc = c + dc[i] * grid[r][c];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;
                visit[nr][nc] = true;
            }
        }
    }
    cout << (visit[n - 1][n - 1] ? "HaruHaru" : "Hing") << '\n';
}