#include <iostream>
#include <vector>
#include <array>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void MakeTree(int cur, vector<bool>& isUsed, vector<vector<int>>& tree, vector<vector<int>>& graph)
{
    isUsed[cur] = true;

    for (int nxt : graph[cur])
    {
        if (isUsed[nxt])
            continue;

        tree[cur].push_back(nxt);
        MakeTree(nxt, isUsed, tree, graph);
    }
}

int SNS(int cur, bool wasEarlier, vector<array<int, 2>>& dp, vector<vector<int>>& tree)
{
    int& result = dp[cur][wasEarlier];
    if (result != -1)
        return result;

    array<int, 2> cnt = { INT_MAX * !wasEarlier,1 };
    for (int nxt : tree[cur])
        cnt[1] += SNS(nxt, true, dp, tree);

    if (wasEarlier)
    {
        for (int nxt : tree[cur])
            cnt[0] += SNS(nxt, false, dp, tree);
    }

    return result = min(cnt[0], cnt[1]);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1), tree(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> isUsed(n + 1, false);
    MakeTree(1, isUsed, tree, graph);

    vector<array<int, 2>> dp(n + 1, { -1,-1 });
    int result = SNS(1, true, dp, tree);
    cout << result << '\n';
}