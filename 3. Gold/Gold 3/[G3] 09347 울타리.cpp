#include <iostream>
#include <vector>
#include <array>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

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

void PushPQ(int y, int x, int k, vector<vector<int>>& dist, priority_queue<Edge>& PQ)
{
    dist[y][x] = k;
    PQ.push({ y,x,k });
}

array<int, 2> GetMaxSection(vector<vector<char>>& map)
{
    int r = map.size();
    int c = map[0].size();

    vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
    priority_queue<Edge> PQ;
    for (int i = 0; i < r; i++)
    {
        PushPQ(i, 0, map[i][0] == '1', dist, PQ);
        PushPQ(i, c - 1, map[i][c - 1] == '1', dist, PQ);
    }
    for (int j = 0; j < c; j++)
    {
        PushPQ(0, j, map[0][j] == '1', dist, PQ);
        PushPQ(r - 1, j, map[r - 1][j] == '1', dist, PQ);
    }

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
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= r || nx < 0 || nx >= c)
                continue;

            int nw = w + (map[ny][nx] == '1');
            if (dist[ny][nx] <= nw)
                continue;

            PushPQ(ny, nx, nw, dist, PQ);
        }
    }

    int value = -1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] != '1' && dist[i][j] > value)
                value = dist[i][j];
        }
    }

    array<int, 2> result = { value,0 };
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            result[1] += (map[i][j] != '1' && dist[i][j] == value);
    }
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int r, c;
        cin >> r >> c;

        vector<vector<char>> map(r, vector<char>(c));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                cin >> map[i][j];
        }

        array<int, 2> result = GetMaxSection(map);
        cout << result[0] << ' ' << result[1] << '\n';
    }
}