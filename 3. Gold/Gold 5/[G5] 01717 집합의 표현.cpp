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
    if (u != v)
        p[u] = v;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;
    n++;

    vector<int> p(n, -1);
    for (int i = 0; i < m; i++)
    {
        int q, a, b;
        cin >> q >> a >> b;

        if (q == 1)
        {
            bool result = (Find(a, p) == Find(b, p));
            if (result)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
        else
            Union(a, b, p);
    }
}