#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

vector<int> dr = { 0,1,1,1 };
vector<int> dc = { 1,0,1,-1 };

bool Check(vector<vector<int>>& grid)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (grid[i][j] == 0)
                continue;
            for (int k = 0; k < 4; k++)
            {
                bool check = true;
                for (int l = 0; l < 4; l++)
                {
                    int nr = i + dr[k] * l;
                    int nc = j + dc[k] * l;

                    if (nr < 0 || nr >= 6 || nc < 0 || nc >= 7)
                    {
                        check = false;
                        break;
                    }

                    check &= (grid[i][j] == grid[nr][nc]);
                }
                if (check) return true;
            }
        }
    }
    return false;
}

void Throw(int c, int v, vector<vector<int>>& grid)
{
    int r = 0;
    while (grid[r][c] != 0)
        r++;
    grid[r][c] = v;
}

pair<int, int> Gimbap(vector<pair<int, int>>& pos)
{
    vector<vector<int>> grid(6, vector<int>(7, 0));
    for (int t = 0; t < 21; t++)
    {
        auto& [s, j] = pos[t];
        Throw(s, +1, grid);
        if (Check(grid)) return { +1,t };

        Throw(j, -1, grid);
        if (Check(grid)) return { -1,t };
    }
    return { 0,0 };
}

int main()
{
    FastIO;

    vector<pair<int, int>> pos(21, { 0,0 });
    for (auto& [s, j] : pos)
    {
        cin >> s >> j;
        s--, j--;
    }

    auto [w, t] = Gimbap(pos);
    if (w == 0) cout << "ss" << '\n';
    else cout << (w > 0 ? "sk" : "ji") << ' ' << t + 1 << '\n';
}