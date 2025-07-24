#include <iostream>
#include <vector>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void TopologySort(vector<vector<int>>& node, vector<int>& indegree)
{
    int n = node.size();

    queue<int> Q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            Q.push(i);
    }

    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        if (Q.empty())
        {
            cout << 0 << '\n';
            return;
        }

        int cur = Q.front();
        Q.pop();

        result[i] = cur;
        for (int nxt : node[cur])
        {
            if (--indegree[nxt] == 0)
                Q.push(nxt);
        }
    }

    for (int i = 0; i < n; i++)
        cout << result[i] + 1 << '\n';
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> node(n);
    vector<int> indegree(n);
    for (int i = 0; i < m; i++)
    {
        int s;
        cin >> s;

        vector<int> singer(s);
        for (int j = 0; j < s; j++)
        {
            cin >> singer[j];
            singer[j]--;
        }

        for (int j = 0; j < s - 1; j++)
        {
            node[singer[j]].push_back(singer[j + 1]);
            indegree[singer[j + 1]]++;
        }
    }
    TopologySort(node, indegree);
}