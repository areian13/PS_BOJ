#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <bit>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void Update(int i, int v, vector<int>& seg)
{
    int t = seg.size() / 2;
    i += t;
    seg[i] += v;

    while (i > 1)
    {
        i /= 2;
        seg[i] = 1LL * seg[i * 2] + seg[i * 2 + 1];
    }
}
int Query(int s, int e, int l, int r, int i, vector<int>& seg)
{
    if (r < s || e < l) return 0;
    if (s <= l && r <= e) return seg[i];

    int m = (l + r) / 2;
    int lq = Query(s, e, l, m, i * 2, seg);
    int rq = Query(s, e, m + 1, r, i * 2 + 1, seg);
    return lq + rq;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<int>> graph(n);
        for (int i = 0; i < k; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            graph[u].push_back(v);
        }

        int t = bit_ceil(1u * m);
        vector<int> seg(t * 2, 0);
        long long result = 0;
        for (int i = 0; i < n; i++)
        {
            sort(graph[i].begin(), graph[i].end());
            for (int v : graph[i])
            {
                result += Query(v + 1, m - 1, 0, t - 1, 1, seg);
                Update(v, 1, seg);
            }
        }
        printf("Test case %d: %lld\n", tc, result);
    }
}