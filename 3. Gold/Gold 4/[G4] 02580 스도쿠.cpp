#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Sudoku
{
    vector<vector<int>> grid, rs, cs, gs;
    bool find;

    Sudoku(vector<vector<int>>& grid) : grid(grid), find(false)
    {
        rs.resize(9, vector<int>(10, false));
        cs = gs = rs;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                Switch(i, j, grid[i][j]);
        }
        MakeSudoku(0);
    }

    void Switch(int r, int c, int v)
    {
        if (v == 0) return;
        rs[r][v] ^= 1;
        cs[c][v] ^= 1;
        gs[r / 3 * 3 + c / 3][v] ^= 1;
    }
    void MakeSudoku(int v)
    {
        if (find) return;
        if (v == 81)
        {
            find = true;
            return;
        }

        int r = v / 9;
        int c = v % 9;

        if (grid[r][c] != 0)
            MakeSudoku(v + 1);
        else
        {
            for (int i = 1; i <= 9; i++)
            {
                if (rs[r][i] || cs[c][i] || gs[r / 3 * 3 + c / 3][i])
                    continue;

                Switch(r, c, i);
                grid[r][c] = i;

                MakeSudoku(v + 1);
                if (find) return;

                grid[r][c] = 0;
                Switch(r, c, i);
            }
        }
    }
};

int main()
{
    FastIO;

    vector<vector<int>> grid(9, vector<int>(9));
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cin >> grid[i][j];
    }

    Sudoku sudoku(grid);
    if (!sudoku.find) cout << -1 << '\n';
    else
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << sudoku.grid[i][j] << ' ';
            cout << '\n';
        }
    }
}