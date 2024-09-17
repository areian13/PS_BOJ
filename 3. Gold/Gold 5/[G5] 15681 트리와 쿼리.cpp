#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int GetSubTree(int u, int p, vector<vector<int>>& tree, vector<int>& dp)
{
    if (dp[u] != -1)
        return dp[u];

    int result = 1;
    for (int v : tree[u])
    {
        if (v == p)
            continue;

        result += GetSubTree(v, u, tree, dp);
    }
    return dp[u] = result;
}

int main()
{
    FastIO;

    int n, r, q;
    cin >> n >> r >> q;
    r--;

    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> dp(n, -1);
    GetSubTree(r, -1, tree, dp);

    while (q--)
    {
        int s;
        cin >> s;
        s--;

        int result = dp[s];
        cout << result << '\n';
    }
}