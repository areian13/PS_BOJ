#include <iostream>
#include <vector>
#include <algorithm>

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

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> querys(m);
    for (auto& query : querys)
        cin >> query.first >> query.second;
    sort(querys.begin(), querys.end());

    vector<int> p(n, -1);
    int r = 0;
    for (int i = 0; i < m; i++)
    {
        if (querys[i].second <= r)
            continue;

        int l = max(r, querys[i].first);
        r = querys[i].second;
        for (int i = l + 1; i <= r; i++)
            Union(l, i, p);
    }

    int result = 0;
    for (int i = 0; i < n; i++)
        result += (p[i] == -1);
    cout << result << '\n';
}