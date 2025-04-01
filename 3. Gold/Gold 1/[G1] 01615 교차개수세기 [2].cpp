#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v;
    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.u < b.u;
    }
};

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        edges[i] = { u - 1,v - 1 };
    }
    sort(edges.begin(), edges.end());

    vector<long long> cnt(n, 0);
    long long result = 0;
    int idx = 0;
    for (int i = 0; i < m; i++)
    {
        while (idx < m && edges[idx].u < edges[i].u)
        {
            cnt[edges[idx].v]++;
            idx++;
        }
        for (int j = edges[i].v + 1; j < n; j++)
            result += cnt[j];
    }
    cout << result << '\n';
}