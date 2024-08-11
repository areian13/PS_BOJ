#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Stu
{
    int h;
    char g;
    string m, s;
};

bool CanMatch(int u, vector<bool>& isVisited,
    vector<int>& a, vector<int>& b, vector<vector<int>>& graph)
{
    isVisited[u] = true;

    for (int v : graph[u])
    {
        if (b[v] != -1)
        {
            if (isVisited[b[v]])
                continue;
            if (!CanMatch(b[v], isVisited, a, b, graph))
                continue;
        }

        a[u] = v;
        b[v] = u;
        return true;
    }
    return false;
}

int MaxMatch(int n, int m, vector<vector<int>>& graph)
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