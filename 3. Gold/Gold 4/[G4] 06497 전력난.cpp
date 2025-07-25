#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Find(int a, vector<int>& p)
{
    if (p[a] == -1)
        return a;
    return p[a] = Find(p[a], p);
}

bool Union(int a, int b, vector<int>& p)
{
    a = Find(a, p);
    b = Find(b, p);
    if (a == b)
        return false;
    p[b] = a;
    return true;
}

struct Edge
{
    int u = -1;
    int v = -1;
    int w = 0;
    bool operator<(const Edge& a) const
    {
        return w < a.w;
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

        vector<Edge> edge(m);
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;

            edge[i] = { u,v,w };
            sum += w;
        }
        sort(edge.begin(), edge.end());

        vector<int> p(n + 1, -1);
        int result = 0;
        for (int i = 0, cnt = 0; ; i++)
        {
            if (Union(edge[i].u, edge[i].v, p))
            {
                result += edge[i].w;
                cnt++;
                if (cnt == n - 1)
                    break;
            }
        }
        cout << sum - result << '\n';
    }

}