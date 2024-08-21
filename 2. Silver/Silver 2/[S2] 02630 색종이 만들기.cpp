#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CheckSame(int y, int x, int size, vector<vector<int>>& paper)
{
    int stdColor = paper[y][x];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (paper[y + i][x + j] != stdColor)
                return false;
        }
    }
    return true;
}

void DC(int y, int x, int size, vector<vector<int>>& paper, array<int, 2>& result)
{
    if (CheckSame(y, x, size, paper))
    {
        result[paper[y][x]]++;
        return;
    }

    int div = size / 2;
    DC(y, x, div, paper, result);
    DC(y, div + x, div, paper, result);
    DC(div + y, x, div, paper, result);
    DC(div + y, div + x, div, paper, result);
}
int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> paper(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> paper[i][j];
    }

    array<int, 2> result = { 0,0 };
    DC(0, 0, n, paper, result);

    cout << result[0] << '\n';
    cout << result[1] << '\n';
}