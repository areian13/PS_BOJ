#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int r, c;
};

bool Runnable(vector<vector<int>>& grid)
{
    int n = grid.size();
    Pos s, p;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 2)
                s = { i,j };
            else if (grid[i][j] == 5)
                p = { i,j };
        }
    }

    int dr = s.r - p.r;
    int dc = s.c - p.c;

    if (dr * dr + dc * dc < 25)
        return false;

    int cnt = 0;
    for (int i = min(s.r, p.r); i <= max(s.r, p.r); i++)
    {
        for (int j = min(s.c, p.c); j <= max(s.c, p.c); j++)
            cnt += (grid[i][j] == 1);
    }
    return cnt >= 3;
}

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

    bool result = Runnable(grid);
    cout << result << '\n';
}