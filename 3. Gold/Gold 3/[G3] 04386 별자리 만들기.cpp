#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Find(int a, vector<int>& p)
{
    if (p[a] == -1)
        return a;
    return p[a] = Find(p[a], p);
}

bool Union(int a, int b, vector<int>& p)
{
    a = Find(a, p);
    b = Find(b, p);
    if (a == b)
        return false;
    p[b] = a;
    return true;
}

struct Edge
{
    int u = -1;
    int v = -1;
    float w = 0;
    bool operator<(const Edge& a) const
    {
        return w < a.w;
    }
};

struct Pos
{
    float x;
    float y;
};

float Dist(Pos a, Pos b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Pos> star(n);
    for (int i = 0; i < n; i++)
        cin >> star[i].x >> star[i].y;

    vector<Edge> edge(n * (n - 1) / 2);
    for (int i = 0, idx = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++, idx++)
            edge[idx] = { i,j,Dist(star[i], star[j]) };
    }
    sort(edge.begin(), edge.end());

    vector<int> p(n, -1);
    float result = 0;

    for (int i = 0, cnt = 0; ; i++)
    {
        if (Union(edge[i].u, edge[i].v, p))
        {
            result += edge[i].w;
            cnt++;
            if (cnt == n - 1)
                break;
        }
    }

    printf("%.2lf\n", result);
}