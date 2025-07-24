#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Find(int a, vector<int>& p)
{
    if (p[a] == -1)
        return a;
    return p[a] = Find(p[a], p);
}

void Union(int a, int b, vector<int>& p)
{
    a = Find(a, p);
    b = Find(b, p);
    if (a == b)
        return;
    p[b] = a;
}

struct Edge
{
    int u = -1;
    int v = -1;
    double w = 0;
    bool operator<(const Edge& a) const
    {
        return w < a.w;
    }
};

struct Pos
{
    double x, y;
};

double Dist(Pos a, Pos b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<Pos> god(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> god[i].x >> god[i].y;

    vector<Edge> edge(n * (n - 1) / 2);
    for (int i = 1, idx = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++, idx++)
            edge[idx] = { i,j,Dist(god[i], god[j]) };
    }
    sort(edge.begin(), edge.end());

    vector<int> p(n + 1, -1);
    int connect = m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        if (Find(a, p) != Find(b, p))
            Union(a, b, p);
        else
            connect--;
    }

    double result = 0;
    for (int i = 0, cnt = 0; ; i++)
    {
        if (Find(edge[i].u, p) != Find(edge[i].v, p))
        {
            Union(edge[i].u, edge[i].v, p);
            result += edge[i].w;
            cnt++;
            if (cnt == n - 1 - connect)
                break;
        }
    }

    printf("%.2lf\n", result);
}