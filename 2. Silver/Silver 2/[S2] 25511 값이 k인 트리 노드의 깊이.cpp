#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void DFS(int u, int p, int d, vector<int>& depth, vector<vector<int>>& tree)
{
    depth[u] = d;

    for (int v : tree[u])
    {
        if (v == p)
            continue;
        DFS(v, u, d + 1, depth, tree);
    }
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> depth(n, -1);
    DFS(0, -1, 0, depth, tree);

    for (int i = 0; i < n; i++)
    {
        int r;
        cin >> r;
        if (r == k) cout << depth[i] << '\n';
    }

}