#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,1,0,-1 };

int BT(int y, int x, vector<vector<int>>& dist, int k, vector<vector<char>>& map)
{
    int r = dist.size();
    int c = dist[0].size();

    if (y == 0 && x == c - 1)
        return (dist[y][x] == k);

    int result = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= r || nx < 0 || nx >= c)
            continue;
        if (map[ny][nx] == 'T' || dist[ny][nx] != -1)
            continue;

        dist[ny][nx] = dist[y][x] + 1;
        result += BT(ny, nx, dist, k, map);
        dist[ny][nx] = -1;
    }
    return result;
}

int main()
{
    FastIO;

    int r, c, k;
    cin >> r >> c >> k;

    vector<vector<char>> map(r, vector<char>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> map[i][j];
    }

    vector<vector<int>> dist(r, vector<int>(c, -1));
    dist[r - 1][0] = 1;

    int result = BT(r - 1, 0, dist, k, map);
    cout << result << '\n';
}