#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

bool CanTrapStar(int y, vector<vector<int>>& map)
{
    int n = map.size();
    int m = map[0].size();

    vector<vector<vector<bool>>> isVisited(n, vector<vector<bool>>(m, vector<bool>(4, false)));

    int i = y;

    int x = 0;
    int d = 0;
    while (true)
    {
        isVisited[y][x][d] = true;

        int ny = y + map[y][x] * dy[d];
        int nx = x + map[y][x] * dx[d];
        d = (d + 1) % 4;

        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            return false;
        if (isVisited[ny][nx][d])
            return true;

        y = ny;
        x = nx;
    }
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        if (CanTrapStar(i, map))
            result.push_back(i + 1);
    }

    int k = result.size();
    cout << k << '\n';
    for (int i = 0; i < k; i++)
        cout << result[i] << ' ';
    cout << '\n';
}