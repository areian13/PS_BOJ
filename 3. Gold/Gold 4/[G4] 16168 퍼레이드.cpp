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

    int v, e;
    cin >> v >> e;

    vector<int> p(v, -1), degree(v, 0);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        Union(a, b, p);
        degree[a]++;
        degree[b]++;
    }

    bool result = true;
    int cnt = 0;
    for (int i = 0; i < v; i++)
    {
        cnt += degree[i] % 2;
        result &= (Find(0, p) == Find(i, p));
    }
    result &= (cnt == 0 || cnt == 2);

    if (result)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}