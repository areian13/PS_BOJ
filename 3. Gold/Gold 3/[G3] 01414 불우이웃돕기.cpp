#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v, c;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.c < b.c;
    }
};

int ctoi(char c)
{
    if ('a' <= c && c <= 'z')
        return c - 'a' + 1;
    return c - 'A' + 27;
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

int MaxDonation(int n, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end());

    vector<int> p(n, -1);
    int result = 0;
    int cnt = 0;
    for (Edge& edge : edges)
    {
        int u = Find(edge.u, p);
        int v = Find(edge.v, p);

        if (u == v)
        {
            result += edge.c;
            continue;
        }

        Union(u, v, p);
        cnt++;
    }
    result = (cnt == n - 1 ? result : -1);

    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Edge> edges;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;

            if (c == '0')
                continue;

            edges.push_back({ i,j,ctoi(c) });
        }
    }

    int result = MaxDonation(n, edges);
    cout << result << '\n';
}