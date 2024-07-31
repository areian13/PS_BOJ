#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanMatch(int u, vector<bool>& isVisited,
    vector<int>& a, vector<int>& b, vector<vector<int>>& graph)
{
    isVisited[u] = true;

    for (int v : graph[u])
    {
        if (b[v] == -1 ||
            !isVisited[b[v]] && CanMatch(b[v], isVisited, a, b, graph))
        {
            a[u] = v;
            b[v] = u;
            return true;
        }
    }
    return false;
}

int MaxFlow(int n, int m, vector<vector<int>>& graph)
{
    vector<int> a(n, -1), b(m, -1);
    int result = 0;
    for (int u = 0; u < n; u++)
    {
        if (a[u] != -1)
            continue;

        vector<bool> isVisited(n, false);
        result += CanMatch(u, isVisited, a, b, graph);
    }
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n = 2'000, m = 2'000;
        vector<vector<pair<char, int>>> map(n, vector<pair<char, int>>(m, { '.',-1 }));

        int h, v;
        cin >> h >> v;

        for (int i = 0; i < h; i++)
        {
            int x, y;
            string w;
            cin >> x >> y >> w;

            for (char c : w)
                map[y][x++] = { c,i };
        }

        vector<vector<int>> graph(h);
        for (int i = 0; i < v; i++)
        {
            int x, y;
            string w;
            cin >> x >> y >> w;

            for (char c : w)
            {
                if (map[y][x].first != '.' && map[y][x].first != c)
                    graph[map[y][x].second].push_back(i);
                y++;
            }
        }

        int result = h + v - MaxFlow(h, v, graph);
        cout << result << '\n';
    }
}