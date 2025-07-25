#include <iostream>
#include <cstdio>
#include <vector>
#include <array>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define INF 1'000'000'000

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { -1,0,1,0 };

struct Pos
{
    int y, x;
};

int main()
{
    FastIO;

    while (true)
    {
        static int tc = 0;

        int n;
        cin >> n;

        if (n == 0)
            break;

        vector<vector<int>> cave(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> cave[i][j];
        }

        vector<vector<int>> dist(n, vector<int>(n, INF));
        dist[0][0] = cave[0][0];

        queue<Pos> Q;
        Q.push({ 0,0 });

        while (!Q.empty())
        {
            int y = Q.front().y;
            int x = Q.front().x;
            Q.pop();

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                    continue;
                if (dist[ny][nx] <= dist[y][x] + cave[ny][nx])
                    continue;

                dist[ny][nx] = dist[y][x] + cave[ny][nx];
                Q.push({ ny,nx });
            }
        }
        printf("Problem %d: %d\n", ++tc, dist[n - 1][n - 1]);
    }
}