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

    int n, m;
    cin >> n >> m;

    vector<int> p(n, -1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        Union(a, b, p);
    }

    int result = 0;
    int pre;
    cin >> pre;
    pre--;
    for (int i = 1; i < n; i++)
    {
        int a;
        cin >> a;
        a--;

        result += (Find(pre, p) != Find(a, p));
        pre = a;
    }
    cout << result << '\n';
}