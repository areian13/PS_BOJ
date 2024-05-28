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
    int w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

int MinMirror(vector<vector<char>>& map)
{
    int n = map.size();

    Pos s = { -1,-1 };
    Pos e = { -1,-1 };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == '#')
            {
                if (s.x == -1)
                    s = { i,j };
                e = { i,j };
            }
        }
    }

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    dist[s.y][s.x] = true;

    priority_queue<Edge> PQ;
    PQ.push({ s,0 });

    while (!PQ.empty())
    {
        int y = PQ.top().v.y;
        int x = PQ.top().v.x;
        int w = PQ.top().w;
        PQ.pop();

        if (dist[y][x] < w)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int ny = y;
            int nx = x;

            while (true)
            {
                ny += dy[i];
                nx += dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                    break;
                if (map[ny][nx] == '*')
                    break;

                if (map[ny][nx] != '.')
                {
                    int nw = w + 1;
                    if (dist[ny][nx] <= nw)
                        continue;

                    dist[ny][nx] = nw;
                    PQ.push({ ny,nx,nw });
                }
            }
        }
    }
    return dist[e.y][e.x] - 1;
}


int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<char>> map(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }

    int result = MinMirror(map);
    cout << result << '\n';
}