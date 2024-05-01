#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int x, y;
};

struct Edge
{
    int u, v;
    long long w;
    bool isConnected;

    friend bool operator>(const Edge& a, const Edge& b)
    {
        if (a.isConnected != b.isConnected)
            return a.isConnected > b.isConnected;
        return a.w > b.w;
    }
};

bool IsOverLappingRoad(int u, int v, vector<Pos>& pos)
{
    int n = pos.size();

    if (pos[u].x == pos[v].x)
    {
        for (int i = 0; i < n; i++)
        {
            if (i == u || i == v)
                continue;

            if (pos[i].x != pos[u].x)
                continue;
            if (min(pos[u].y, pos[v].y) < pos[i].y && pos[i].y < max(pos[u].y, pos[v].y))
                return true;
        }
    }
    else
    {
        double a = (double)(pos[u].y - pos[v].y) / (pos[u].x - pos[v].x);
        double b = pos[v].x;
        double c = pos[v].y;

        for (int i = 0; i < n; i++)
        {
            if (i == u || i == v)
                continue;

            double y1 = a * (pos[i].x - b) + c;
            double y2 = pos[i].y;
            if (y1 != y2)
                continue;
            if (min(pos[u].y, pos[v].y) < y2 && y2 < max(pos[u].y, pos[v].y))
                return true;
        }
    }
    
    return false;
}

long long Dist(Pos& a, Pos& b)
{
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;

    return dx * dx + dy * dy;
}

int Find(int u, vector<int>& p)
{
    if (p[u] == -1)
        return u;
    return p[u] = Find(p[u], p);
}

void Union(int u, int v, vector<int>& p)
{
    p[v] = u;
}

long long MaxHighwayToll(int n, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end(), greater<Edge>());

    vector<int> p(n, -1);
    long long result = 0;
    for (Edge& edge : edges)
    {
        int u = Find(edge.u, p);
        int v = Find(edge.v, p);

        if (u == v)
            continue;

        Union(u, v, p);
        result += edge.w;
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<Pos> pos(n);
    for (int i = 0; i < n; i++)
        cin >> pos[i].x >> pos[i].y;

    vector<vector<bool>> isConnected(n, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        isConnected[u][v] = true;
        isConnected[v][u] = true;
    }

    vector<Edge> edges;
    for (int u = 0; u < n - 1; u++)
    {
        for (int v = u + 1; v < n; v++)
        {
            if (IsOverLappingRoad(u, v, pos))
                continue;

            long long w = Dist(pos[u], pos[v]) * !isConnected[u][v];
            edges.push_back({ u,v,w,isConnected[u][v] });
        }
    }

    long long result = MaxHighwayToll(n, edges);
    cout << result << '\n';
}