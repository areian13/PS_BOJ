#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x;
};

struct Edge
{
    int u;
    int v;
    int d;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.d < b.d;
    }
};

int Dist(Pos& a, Pos& b)
{
    int dx = a.x - b.x;
    int dy = a.y - b.y;

    return dx * dx + dy * dy;
}

int Find(int a, vector<int>& p)
{
    if (p[a] == -1)
        return a;
    return p[a] = Find(p[a], p);
}

void Union(int a, int b, vector<int>& p)
{
    p[b] = a;
}

int MinCost(int c, vector<Pos>& pos)
{
    int n = pos.size();

    vector<Edge> edges;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int d = Dist(pos[i], pos[j]);
            if (d >= c)
                edges.push_back({ i,j,d });
        }
    }
    sort(edges.begin(), edges.end());

    vector<int> p(n, -1);
    int result = 0;
    int cnt = 0;
    for (Edge& edge : edges)
    {
        int u = Find(edge.u, p);
        int v = Find(edge.v, p);
        if (u != v)
        {
            Union(u, v, p);
            result += edge.d;
            cnt++;

            if (cnt == n - 1)
                break;
        }
    }
    result = (cnt == n - 1 ? result : -1);

    return result;
}

int main()
{
    FastIO;

    int n, c;
    cin >> n >> c;

    vector<Pos> pos(n);
    for (int i = 0; i < n; i++)
        cin >> pos[i].x >> pos[i].y;

    int result = MinCost(c, pos);
    cout << result << '\n';
}