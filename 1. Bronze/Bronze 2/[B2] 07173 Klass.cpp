#include <iostream>
#include <cstdio>
#include <vector>
#include <array>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 4> dr = { 0,1,0,-1 };
array<int, 4> dc = { 1,0,-1,0 };

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;

            map[i][j] = c - '0';
        }
    }

    double result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int sum = 0;
            int cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                int nr = i + dr[k];
                int nc = j + dc[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                cnt++;
                sum += abs(map[nr][nc] - map[i][j]);
            }

            result += (double)sum / cnt;
        }
    }

    printf("%.4lf\n", result);
}