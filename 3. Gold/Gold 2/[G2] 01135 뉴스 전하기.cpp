#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int DFS(int cur, vector<vector<int>>& tree)
{
    if (tree[cur].empty())
        return 0;

    vector<int> sub;
    for (int nxt : tree[cur])
        sub.push_back(DFS(nxt, tree));
    sort(sub.begin(), sub.end(), greater<int>());

    int s = sub.size();
    int result = 0;
    for (int i = 0; i < s; i++)
        result = max(result, sub[i] + (i + 1));
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> tree(n);
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;

        if (p == -1)
            continue;

        tree[p].push_back(i);
    }

    int result = DFS(0, tree);
    cout << result << '\n';
}