#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SIZE 5'000

array<int, 4> dy = { 0,-1,0,1 };
array<int, 4> dx = { 1,0,-1,0 };

void MakeSwirl(int r1, int c1, int r2, int c2, vector<vector<int>>& map)
{
    int num = 0, last = (SIZE * 2 + 1) * (SIZE * 2 + 1);
    int dir = 0, cnt = 1;
    int y = SIZE, x = SIZE;
    while (true)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < cnt; j++)
            {
                if (num == last)
                    return;

                num++;
                if (r1 <= y && y <= r2 && c1 <= x && x <= c2)
                    map[y - r1][x - c1] = num;
                y += dy[dir];
                x += dx[dir];
            }
            dir = (dir + 1) % 4;
        }
        cnt++;
    }
}

void PrintSwirl(vector<vector<int>>& map)
{
    int n = map.size();
    int m = map[0].size();

    vector<vector<int>> digit(n, vector<int>(m));
    int maxD = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            digit[i][j] = log10(map[i][j]) + 1;
            maxD = max(maxD, digit[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < maxD - digit[i][j]; k++)
                cout << ' ';
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    FastIO;

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1 += SIZE, c1 += SIZE, r2 += SIZE, c2 += SIZE;

    vector<vector<int>> map(r2 - r1 + 1, vector<int>(c2 - c1 + 1));
    MakeSwirl(r1, c1, r2, c2, map);

    PrintSwirl(map);
}