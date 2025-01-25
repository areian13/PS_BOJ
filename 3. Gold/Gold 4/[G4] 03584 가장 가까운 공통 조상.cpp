#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int LCA(int u, int v, vector<int>& parent)
{
    int n = parent.size();

    vector<bool> isVisited(n, false);
    while (u != -1)
    {
        isVisited[u] = true;
        u = parent[u];
    }

    while (!isVisited[v])
        v = parent[v];
    return v;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        vector<int> parent(n, -1);
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;

            parent[b] = a;
        }

        int u, v;
        cin >> u >> v;
        u--, v--;

        int result = LCA(u, v, parent);
        cout << result + 1 << '\n';
    }
}