#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 12> dy = { 1,0,-1,0,2,1,-1,-2,-2,-1,1,2, };
array<int, 12> dx = { 0,1,0,-1,1,2,2,1,-1,-2,-2,-1, };

struct Pos
{
    int y, x, z;
};

int MinDist(int y, int x, vector<vector<vector<int>>>& dist)
{
    int k = dist[0][0].size() - 1;

    int result = INT_MAX;
    for (int z = 0; z <= k; z++)
    {
        if (dist[y][x][z] == -1)
            continue;
        result = min(result, dist[y][x][z]);
    }
    result = (result == INT_MAX ? -1 : result);
    return result;
}

int main()
{
    FastIO;

    int k, w, h;
    cin >> k >> w >> h;

    vector<vector<int>> map(h, vector<int>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            cin >> map[i][j];
    }

    vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(k + 1, -1)));
    dist[0][0][0] = 0;

    queue<Pos> Q;
    Q.push({ 0,0,0 });

    while (!Q.empty())
    {
        auto [y, x, z] = Q.front();
        Q.pop();

        for (int i = 0; i < 12; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nz = z + (i >= 4);

            if (ny < 0 || ny >= h || nx < 0 || nx >= w || nz > k)
                continue;
            if (map[ny][nx] == 1 || dist[ny][nx][nz] != -1)
                continue;

            dist[ny][nx][nz] = dist[y][x][z] + 1;
            Q.push({ ny,nx,nz });
        }
    }

    int result = MinDist(h - 1, w - 1, dist);
    cout << result << '\n';
}