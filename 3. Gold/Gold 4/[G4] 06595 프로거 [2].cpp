#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    double x, y;

    friend double Dist(Pos& a, Pos& b)
    {
        double dx = a.x - b.x;
        double dy = a.y - b.y;

        return sqrt(dx * dx + dy * dy);
    }
};

struct Edge
{
    int v;
    double w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w < b.w;
    }
};

bool CanGoToFlona(int s, int e, double maxW, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<bool> isVisited(n, false);
    isVisited[s] = true;

    queue<int> Q;
    Q.push(s);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            double w = edge.w;

            if (isVisited[v] || w > maxW)
                continue;

            isVisited[v] = true;
            Q.push(v);
        }
    }
    return isVisited[e];
}

double GetMinJump(vector<Pos>& pos)
{
    int n = pos.size();

    vector<vector<Edge>> graph(n);
    vector<double> edgeW;
    for (int u = 0; u < n - 1; u++)
    {
        for (int v = u + 1; v < n; v++)
        {
            double w = Dist(pos[u], pos[v]);

            edgeW.push_back(w);
            graph[u].push_back({ v,w });
            graph[v].push_back({ u,w });
        }
    }
    sort(edgeW.begin(), edgeW.end());

    for (double w : edgeW)
    {
        if (CanGoToFlona(0, 1, w, graph))
            return w;
    }
}

int main()
{
    FastIO;

    int tc = 0;
    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        vector<Pos> pos(n);
        for (int i = 0; i < n; i++)
            cin >> pos[i].x >> pos[i].y;

        double result = GetMinJump(pos);
        printf("Scenario #%d\n", ++tc);
        printf("Frog Distance = %.3lf\n\n", result);
    }
}