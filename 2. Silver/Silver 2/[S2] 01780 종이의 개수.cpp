#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void CountPaper(int y, int x, int n, vector<vector<int>>& paper, array<int, 3>& result)
{
    int b = paper[y][x];
    for (int i = y; i < y + n; i++)
    {
        for (int j = x; j < x + n; j++)
        {
            if (paper[i][j] == b)
                continue;

            n /= 3;
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    int ny = y + k * n;
                    int nx = x + l * n;
                    CountPaper(ny, nx, n, paper, result);
                }
            }
            return;
        }
    }
    result[b + 1]++;
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

    array<int, 3> result = { 0,0,0 };
    CountPaper(0, 0, n, paper, result);

    for (int i = 0; i < 3; i++)
        cout << result[i] << '\n';
}