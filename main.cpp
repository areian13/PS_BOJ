#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Star
{
    int x, y, b;

    friend auto operator <=> (const Star& a, const Star& b) = default;
};
struct Edge
{
    int u, v;
    long long w;
};
struct DSU
{
    vector<int> p;
    DSU(int n) { p.resize(n, -1); }
    int Find(int u) { return p[u] < 0 ? u : p[u] = Find(p[u]); }
    void Union(int u, int v)
    {
        u = Find(u), v = Find(v);
        if (u == v)
            return;
        p[u] += p[v], p[v] = u;
    }
};


long long MinCost(vector<Star>& stars)
{
    int n = stars.size();

    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += (stars[i].b >= 80);

    if (cnt * 2 > n)
        return -1;

    vector<Edge> edges;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            Star& s = stars[i];
            Star& t = stars[j];

            int dx = s.x - t.x;
            int dy = s.y - t.y;
            long long w = 1LL * (s.b + t.b) * (dx * dx + dy * dy + 1);
            if (s.b >= 80 && t.b >= 80)
                w = 0;
            edges.push_back({ i,j,w });
        }
    }
    sort(edges.begin(), edges.end(),
        [](const Edge& a, const Edge& b) { return a.w < b.w; }
    );

    DSU dsu(n);
    long long result = 0;
    for (auto& [u, v, w] : edges)
    {
        if (dsu.Find(u) == dsu.Find(v))
            continue;
        dsu.Union(u, v);
        result += w;
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    map<int, map<int, int>> temp;
    for (int i = 0; i < n; i++)
    {
        int x, y, b;
        cin >> x >> y >> b;

        temp[x][y] = max(temp[x][y], b);
    }
    vector<Star> stars;
    for (auto it = temp.begin(); it != temp.end(); it++)
    {
        auto& ymap = it->second;
        for (auto jt = ymap.begin(); jt != ymap.end(); jt++)
            stars.push_back({ it->first,jt->first,jt->second });
    }
    temp.clear();
    n = stars.size();

    long long result = MinCost(stars);
    cout << result << '\n';
}