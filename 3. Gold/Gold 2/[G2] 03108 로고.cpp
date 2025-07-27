#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Rect
{
    int x1, y1, x2, y2;
};
struct UnionFind
{
    vector<int> p;
    UnionFind(int n) { p.resize(n, -1); }
    int Find(int u) { return p[u] < 0 ? u : p[u] = Find(p[u]); }
    void Union(int u, int v)
    {
        u = Find(u), v = Find(v);
        if (u == v)
            return;
        if (u < v)
            swap(u, v);
        p[v] = u;
    }
};

bool IsOverwrap(Rect& a, Rect& b)
{
    if (a.x2 < b.x1)
        return false;
    if (a.x1 > b.x2)
        return false;
    if (a.y2 < b.y1)
        return false;
    if (a.y1 > b.y2)
        return false;
    if (a.x1 < b.x1 && b.x2 < a.x2 &&
        a.y1 < b.y1 && b.y2 < a.y2)
        return false;
    if (b.x1 < a.x1 && a.x2 < b.x2 &&
        b.y1 < a.y1 && a.y2 < b.y2)
        return false;
    return true;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Rect> rects(n + 1);
    rects[n] = { 0,0,0,0 };
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        rects[i] = { x1,y1,x2,y2 };
    }

    UnionFind uf(n + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n + 1; j++)
        {
            if (IsOverwrap(rects[i], rects[j]))
                uf.Union(i, j);
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
        result += (uf.p[i] < 0);
    cout << result << '\n';
}