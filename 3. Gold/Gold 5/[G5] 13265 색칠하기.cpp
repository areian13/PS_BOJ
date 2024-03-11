#include <iostream>
#include <vector>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanColoring(vector<vector<int>>& graph)
{
    int n = graph.size();

    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] != -1)
            continue;

        color[i] = 0;

        queue<int> Q;
        Q.push(i);

        while (!Q.empty())
        {
            int cur = Q.front();
            Q.pop();

            for (int nxt : graph[cur])
            {
                if (color[nxt] == color[cur])
                    return false;
                if (color[nxt] != -1)
                    continue;

                color[nxt] = (color[cur] + 1) % 2;
                Q.push(nxt);
            }
        }
    }
    return true;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            x--, y--;

            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        string result = CanColoring(graph) ? "possible" : "impossible";
        cout << result << '\n';
    }
}