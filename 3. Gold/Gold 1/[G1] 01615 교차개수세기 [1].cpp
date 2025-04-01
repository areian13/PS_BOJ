#include <iostream>
#include <vector>
#include <algorithm>
#include <bit>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v;
    friend bool operator<(const Edge& a, const Edge& b)
    {
        if (a.u != b.u)
            return a.u < b.u;
        return a.v < b.v;
    }
};

long long SegTree(int start, int end, int idx, int l, int r, vector<long long>& cnt)
{
    if (r < start || end < l)
        return 0;
    if (start <= l && r <= end)
        return cnt[idx];

    int mid = (l + r) / 2;
    return SegTree(start, end, idx * 2, l, mid, cnt)
        + SegTree(start, end, idx * 2 + 1, mid + 1, r, cnt);
}

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

    int t = bit_ceil((unsigned int)n);

    vector<long long> cnt(t * 2, 0);
    long long result = 0;
    for (int i = 0; i < m; i++)
    {
        result += SegTree(edges[i].v + 1, n - 1, 1, 0, t - 1, cnt);

        int idx = t + edges[i].v;
        cnt[idx]++;
        while (idx > 1)
        {
            idx /= 2;
            cnt[idx] = cnt[idx * 2] + cnt[idx * 2 + 1];
        }
    }
    cout << result << '\n';
}