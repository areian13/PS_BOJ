#include <iostream>
#include <vector>
#include <unordered_map>
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

    vector<int> p(n, -1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;

        Union(x, y, p);
    }

    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++)
        cnt[Find(i, p)]++;

    int c, h, k;
    cin >> c >> h >> k;
    c--, h--;

    vector<int> cand;
    for (auto& it : cnt)
    {
        if (it.first != Find(c, p) && it.first != Find(h, p))
            cand.push_back(it.second);
    }
    sort(cand.begin(), cand.end(), greater<int>());

    int result = cnt[Find(c, p)];
    k = min(k, (int)cand.size());
    for (int i = 0; i < k; i++)
        result += cand[i];
    cout << result << '\n';
}