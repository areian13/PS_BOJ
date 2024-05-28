#include <iostream>
#include <vector>
#include <cfloat>
#include <queue>
#include <array>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

struct Pos
{
    int y, x;
};

struct Edge
{
    Pos v;
    double s;
    double w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

double FastestTime(double v, vector<vector<int>>& map)
{
    int r = map.size();
    int c = map[0].size();

    vector<vector<double>> dist(r, vector<double>(c, DBL_MAX));
    dist[0][0] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ 0,0,v,0 });

    while (!PQ.empty())
    {
        int y = PQ.top().v.y;
        int x = PQ.top().v.x;
        double s = PQ.top().s;
        double w = PQ.top().w;
        PQ.pop();

        if (dist[y][x] < w)
            continue;;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= r || nx < 0 || nx >= c)
                continue;

            double nw = w + 1 / s;
            if (dist[ny][nx] <= nw)
                continue;

            double ns = s * pow(2, map[y][x] - map[ny][nx]);
            dist[ny][nx] = nw;
            PQ.push({ ny,nx,ns,nw });
        }
    }
    return dist[r - 1][c - 1];
}

int main()
{
    FastIO;

    int v, r, c;
    cin >> v >> r >> c;

    vector<vector<int>> map(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> map[i][j];
    }

    double result = FastestTime(v, map);
    lf(2);
    cout << result << '\n';
}