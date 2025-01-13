#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int r, c, d;
};

array<int, 4> dr = { 0,1,0,-1 };
array<int, 4> dc = { 1,0,-1,0 };

int MinMirror(vector<vector<char>>& map)
{
    int h = map.size();
    int w = map[0].size();

    Pos s = { -1,-1 };
    Pos e = { -1,-1 };
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (map[i][j] == 'C')
            {
                if (s.r == -1)
                    s = { i,j };
                e = { i,j };
            }
        }
    }

    vector<vector<vector<int>>> dist(4, vector<vector<int>>(h, vector<int>(w, INT_MAX)));
    queue<Pos> Q;
    for (int i = 0; i < 4; i++)
    {
        dist[i][s.r][s.c] = 0;
        Q.push({ s.r,s.c,i });
    }

    while (!Q.empty())
    {
        int r = Q.front().r;
        int c = Q.front().c;
        int d = Q.front().d;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= h || nc < 0 || nc >= w)
                continue;

            int nd = dist[d][r][c] + (i != d);
            if (map[nr][nc] == '*' || dist[i][nr][nc] <= nd)
                continue;

            dist[i][nr][nc] = nd;
            Q.push({ nr,nc,i });
        }
    }

    int result = INT_MAX;
    for (int i = 0; i < 4; i++)
        result = min(result, dist[i][e.r][e.c]);
    return result;
}


int main()
{
    FastIO;

    int w, h;
    cin >> w >> h;

    vector<vector<char>> map(h, vector<char>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            cin >> map[i][j];
    }

    int result = MinMirror(map);
    cout << result << '\n';
}