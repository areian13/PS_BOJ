#include <iostream>
#include <vector>
#include <array>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x;
};

struct Info
{
    Pos R, B;
};

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { -1,0,1,0 };

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));
    Pos R, B;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 'R')
                R = { i,j };
            else if (map[i][j] == 'B')
                B = { i,j };
        }
    }
    vector<vector<vector<vector<int>>>> dist(n, vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(m, -1))));
    dist[R.y][R.x][B.y][B.x] = 0;

    queue<Info> Q;
    Q.push({ R,B });

    bool result = false;
    while (!Q.empty())
    {
        int ry = Q.front().R.y;
        int rx = Q.front().R.x;

        int by = Q.front().B.y;
        int bx = Q.front().B.x;
        Q.pop();

        if (dist[ry][rx][by][bx] == 10)
            continue;

        for (int i = 0; i < 4; i++)
        {
            bool rCan = false;
            bool bCan = false;

            int nry = ry;
            int nrx = rx;

            int nby = by;
            int nbx = bx;

            while (map[nry + dy[i]][nrx + dx[i]] != '#' && !(nry + dy[i] == nby && nrx + dx[i] == nbx))
            {
                nry += dy[i];
                nrx += dx[i];

                if (map[nry][nrx] == 'O')
                    rCan = true;
            }
            while (map[nby + dy[i]][nbx + dx[i]] != '#' && !(nby + dy[i] == nry && nbx + dx[i] == nrx))
            {
                nby += dy[i];
                nbx += dx[i];

                if (map[nby][nbx] == 'O' || map[nby + dy[i]][nbx + dx[i]] == 'O')
                    bCan = true;
            }
            while (map[nry + dy[i]][nrx + dx[i]] != '#' && !(nry + dy[i] == nby && nrx + dx[i] == nbx))
            {
                nry += dy[i];
                nrx += dx[i];

                if (map[nry][nrx] == 'O')
                    rCan = true;
            }

            if (rCan && !bCan)
            {
                result = true;
                goto RESULT;
            }
            if (bCan || dist[nry][nrx][nby][nbx] != -1)
                continue;

            dist[nry][nrx][nby][nbx] = dist[ry][rx][by][bx] + 1;
            Q.push({ { nry,nrx },{ nby,nbx } });
        }
    }
RESULT:
    cout << result << '\n';
}