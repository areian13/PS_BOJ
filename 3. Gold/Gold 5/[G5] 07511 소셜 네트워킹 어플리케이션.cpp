#include <iostream>
#include <cstdio>
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

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n, k;
        cin >> n >> k;

        vector<int> p(n, -1);
        for (int i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;

            Union(a, b, p);
        }

        int m;
        cin >> m;

        printf("Scenario %d:\n", tc);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;

            bool result = (Find(a, p) == Find(b, p));
            printf("%d\n", result);
        }
        printf("\n");
    }
}