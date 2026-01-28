#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Difficulty(vector<vector<char>>& grid)
{
    int w = 0, d = 0, a = 0, v = 0, s = 0, e = 0;
    for (auto& r : grid)
    {
        for (char c : r)
        {
            w += (c == '#');
            d += (c == 'U' || c == 'D' || c == 'L' || c == 'R');
            a += (c == 'A');
            v += (c == 'V');
            s += (c == 'S');
            e += (c == 'E');
        }
    }

    if (s != 1 || e != 1) return -1;
    if (w <= 1 && d <= 1 && a == 0 && v == 0) return 1;
    if (a == 0 && v == 0) return 2;
    if (a == 0) return 3;
    return 4;
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

    int result = Difficulty(grid);
    cout << result << '\n';
}