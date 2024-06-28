#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

struct CrossRoad
{
    int i;
    bool d;
    array<int, 2> t;

    friend bool operator<(const CrossRoad& a, const CrossRoad& b)
    {
        return a.i < b.i;
    }
};

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

array<int, 2> CurState(int w, CrossRoad& crossRoad)
{
    int sum = 0;
    bool d = crossRoad.d;
    while (sum + crossRoad.t[d] <= w)
    {
        sum += crossRoad.t[d];
        d = !d;
    }
    return { sum + crossRoad.t[d],d };
}

int Dist(int w, bool d, CrossRoad& crossRoad)
{
    array<int, 2> cs = CurState(w, crossRoad);

    if (cs[1] == d)
        return 0;
    return cs[0] - w;
}

string MinDist(Pos& s, Pos& t, vector<CrossRoad>& crossRoads, vector<vector<char>>& map)
{
    int n = map.size();
    int m = map[0].size();

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[s.y][s.x] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ s,0 });

    while (!PQ.empty())
    {
        int y = PQ.top().v.y;
        int x = PQ.top().v.x;
        int w = PQ.top().w;
        PQ.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (map[ny][nx] == '.')
                continue;

            int k = map[ny][nx] - '0';
            int nw = w + 1 + (0 <= k && k <= 9 ? Dist(w, i % 2, crossRoads[k]) : 0);
            if (dist[ny][nx] <= nw)
                continue;

            dist[ny][nx] = nw;
            PQ.push({ ny,nx,nw });
        }
    }

    if (dist[t.y][t.x] == INT_MAX)
        return "impossible";
    return to_string(dist[t.y][t.x]);
}

int main()
{
    FastIO;

    while (true)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        vector<vector<char>> map(n, vector<char>(m));
        vector<CrossRoad> crossRoads;
        Pos s = { -1,-1 };
        Pos t = { -1,-1 };
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> map[i][j];

                if (map[i][j] == 'A')
                    s = { i,j };
                if (map[i][j] == 'B')
                    t = { i,j };
                if ('0' <= map[i][j] && map[i][j] <= '9')
                    crossRoads.push_back({ map[i][j] - '0' });
            }
        }
        sort(crossRoads.begin(), crossRoads.end());

        int k = crossRoads.size();
        for (int i = 0; i < k; i++)
        {
            int a, b;
            char d;
            cin >> i >> d >> a >> b;

            crossRoads[i] = { i,d == '|',a,b };
        }

        string result = MinDist(s, t, crossRoads, map);
        cout << result << '\n';
    }
}