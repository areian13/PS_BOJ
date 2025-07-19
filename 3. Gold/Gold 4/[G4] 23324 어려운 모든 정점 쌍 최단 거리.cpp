#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Find(int u, vector<int>& p)
{
    if (p[u] == -1)
        return u;
    return p[u] = Find(p[u], p);
}
void Union(int u, int v, vector<int>& p)
{
    u = Find(u, p);
    v = Find(v, p);
    if (u == v)
        return;
    p[u] = v;
}

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;
    k--;

    vector<int> p(n, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        if (i != k)
            Union(u, v, p);
    }

    vector<int> cnt = { 0,0 };
    for (int i = 0; i < n; i++)
        cnt[Find(0, p) == Find(i, p)]++;

    long long result = 1LL * cnt[0] * cnt[1];
    cout << result << '\n';
}