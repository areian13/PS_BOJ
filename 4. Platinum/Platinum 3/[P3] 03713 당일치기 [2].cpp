#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define INF INT_MAX

struct Stu
{
    int h;
    char g;
    string m, s;
};

void BFS(vector<bool>& isUsed, vector<int>& level, vector<int>& b,
    vector<vector<int>>& graph)
{
    int n = graph.size();

    queue<int> Q;
    for (int i = 0; i < n; i++)
    {
        if (!isUsed[i])
        {
            level[i] = 0;
            Q.push(i);
        }
    }

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int v : graph[u])
        {
            if (b[v] == -1 || level[b[v]] != INF)
                continue;

            level[b[v]] = level[u] + 1;
            Q.push(b[v]);
        }
    }
}

bool CanMatch(int u, vector<bool>& isUsed, vector<int>& level,
    vector<int>& a, vector<int>& b, vector<vector<int>>& graph)
{
    for (int v : graph[u])
    {
        if (b[v] != -1)
        {
            if (level[b[v]] != level[u] + 1)
                continue;
            if (!CanMatch(b[v], isUsed, level, a, b, graph))
                continue;
        }

        a[u] = v;
        b[v] = u;
        return isUsed[u] = true;
    }
    return false;
}

int MaxMatch(int n, int m, vector<vector<int>>& graph)
{
    vector<int> a(n, -1), b(m, -1);
    vector<bool> isUsed(n, false);
    int result = 0;
    while (true)
    {
        vector<int> level(n, INF);
        BFS(isUsed, level, b, graph);

        int flow = 0;
        for (int u = 0; u < n; u++)
            flow += (!isUsed[u] && CanMatch(u, isUsed, level, a, b, graph));

        if (flow == 0)
            break;

        result += flow;
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
        int n;
        cin >> n;

        vector<vector<Stu>> stus(2);
        for (int i = 0; i < n; i++)
        {
            int h;
            char g;
            string m, s;
            cin >> h >> g >> m >> s;

            stus[g == 'F'].push_back({ h,g,m,s });
        }

        int m = stus[0].size();
        int f = stus[1].size();
        vector<vector<int>> graph(m);
        for (int u = 0; u < m; u++)
        {
            for (int v = 0; v < f; v++)
            {
                Stu& a = stus[0][u];
                Stu& b = stus[1][v];
                if (abs(a.h - b.h) > 40)
                    continue;
                if (a.m != b.m || a.s == b.s)
                    continue;

                graph[u].push_back(v);
            }
        }

        int result = n - MaxMatch(m, f, graph);
        cout << result << '\n';
    }
}