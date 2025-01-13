#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x;
};

struct Edge
{
    Pos v;
    int d;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.d > b.d;
    }
};

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

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
                if (s.x == -1)
                    s = { i,j };
                e = { i,j };
            }
        }
    }

    vector<vector<int>> dist(h, vector<int>(w, INT_MAX));
    dist[s.y][s.x] = -1;

    priority_queue<Edge> PQ;
    PQ.push({ s,-1 });

    while (!PQ.empty())
    {
        int y = PQ.top().v.y;
        int x = PQ.top().v.x;
        int d = PQ.top().d;
        PQ.pop();

        if (dist[y][x] < d)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int ny = y;
            int nx = x;

            while (true)
            {
                ny += dy[i];
                nx += dx[i];

                if (ny < 0 || ny >= h || nx < 0 || nx >= w)
                    break;
                if (map[ny][nx] == '*')
                    break;

                int nd = d + 1;
                if (dist[ny][nx] <= nd)
                    continue;

                dist[ny][nx] = nd;
                PQ.push({ ny,nx,nd });
            }
        }
    }
    return dist[e.y][e.x];
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