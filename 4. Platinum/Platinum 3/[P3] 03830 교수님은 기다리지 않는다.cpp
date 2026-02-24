#include <iostream>
#include <vector>
#include <climits>
#include <map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct MST
{
    vector<int> p, d;

    MST(int n)
    {
        p.resize(n, -1);
        d.resize(n, 0);
    }
    int Find(int u)
    {
        if (p[u] < 0) return u;

        int parent = Find(p[u]);
        d[u] += d[p[u]];
        return p[u] = parent;
    }
    void Union(int u, int v, int w)
    {
        int ur = Find(u), vr = Find(v);
        if (ur == vr) return;

        if (p[ur] > p[vr])
            swap(ur, vr), swap(u, v), w *= -1;

        d[vr] = d[u] - d[v] + w;
        p[ur] += p[vr], p[vr] = ur;
    }
};

int main()
{
    FastIO;

    while (true)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        MST mst(n);
        for (int i = 0; i < m; i++)
        {
            char c;
            int u, v;
            cin >> c >> u >> v;
            u--, v--;

            if (c == '!')
            {
                int w;
                cin >> w;

                if (mst.Find(u) == mst.Find(v))
                    continue;

                mst.Union(u, v, w);
            }
            else
            {
                if (mst.Find(u) != mst.Find(v))
                    cout << "UNKNOWN" << '\n';
                else
                    cout << mst.d[v] - mst.d[u] << '\n';
            }
        }
    }
}