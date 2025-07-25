#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<array<int, 9>, 9> sudoku;
array<array<bool, 10>, 9> row;
array<array<bool, 10>, 9> col;
array<array<bool, 10>, 9> sqr;

void Toggle(int y, int x, int num)
{
    row[y][num] = !row[y][num];
    col[x][num] = !col[x][num];
    sqr[y / 3 * 3 + x / 3][num] = !sqr[y / 3 * 3 + x / 3][num];
}

void DFS(int cnt)
{
    if (cnt == 81)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << sudoku[i][j];
            cout << '\n';
        }
        exit(0);
    }

    int y = cnt / 9;
    int x = cnt % 9;

    if (sudoku[y][x] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (row[y][i] || col[x][i] || sqr[y / 3 * 3 + x / 3][i])
                continue;
         
            Toggle(y, x, i);
            sudoku[y][x] = i;

            DFS(cnt + 1);

            sudoku[y][x] = 0;
            Toggle(y, x, i);
        }
    }
    else
        DFS(cnt + 1);
}

int main()
{
    FastIO;

    for (int i = 0; i < 9; i++)
    {
        string line;
        cin >> line;

        for (int j = 0; j < 9; j++)
        {
            int num = (line[j] - '0');
            sudoku[i][j] = num;
            if (num != 0)
                Toggle(i, j, num);
        }
    }

    DFS(0);
}