#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, c, f;
    Edge* rev;

    Edge() : Edge(-1, 0) {}
    Edge(int v, int c) : v(v), c(c), f(0), rev(nullptr) {}

    int Spare()
    {
        return c - f;
    }
    void AddFlow(int f)
    {
        this->f += f;
        rev->f -= f;
    }
};

int NoMeetPath(int s, int t, vector<vector<Edge*>>& graph, bool forPath = false)
{
    int n = graph.size();

    int result = 0;
    while (true)
    {
        vector<int> p(n, -1);
        vector<Edge*> path(n);

        queue<int> Q;
        Q.push(s);

        while (!Q.empty() && p[t] == -1)
        {
            int u = Q.front();
            Q.pop();

            for (Edge* edge : graph[u])
            {
                int v = edge->v;
                int w = edge->Spare();

                if (!forPath && (w <= 0 || p[v] != -1))
                    continue;
                if (forPath && (edge->f == 0 || p[v] != -1))
                    continue;

                p[v] = u;
                path[v] = edge;
                Q.push(v);

                if (v == t)
                    break;
            }
        }

        if (p[t] == -1)
            break;

        if (forPath)
        {
            vector<int> result;
            for (int i = t; i != s; i = p[i])
            {
                if (result.empty() || i % 2 == 0)
                    result.push_back(i / 2);
                path[i]->AddFlow(-1);
            }
            result.push_back(s / 2);

            for (int i = result.size() - 1; i >= 0; i--)
                cout << result[i] + 1 << ' ';
            cout << '\n';
            return -1;
        }

        for (int i = t; i != s; i = p[i])
            path[i]->AddFlow(+1);
        result++;
    }
    return result;
}

int main()
{
    FastIO;

    int tc = 0;
    while (true)
    {
        int k, n;
        cin >> k >> n;

        if (k == 0 && n == 0)
            break;

        vector<vector<Edge*>> graph(n * 2);
        cin.ignore();
        for (int u = 0; u < n * 2; u += 2)
        {
            Edge* e1 = new Edge(u + 1, 1);
            Edge* e2 = new Edge(u, 0);
            e1->rev = e2;
            e2->rev = e1;
            graph[u].push_back(e1);
            graph[u + 1].push_back(e2);

            string line;
            getline(cin, line);

            stringstream ss(line);
            string sv;
            while (ss >> sv)
            {
                int v = (stoi(sv) - 1) * 2;

                e1 = new Edge(v, 1);
                e2 = new Edge(u + 1, 0);
                e1->rev = e2;
                e2->rev = e1;
                graph[u + 1].push_back(e1);
                graph[v].push_back(e2);
            }
        }

        int flow = NoMeetPath(1, 2, graph);

        cout << "Case" << ' ' << ++tc << ':' << '\n';
        if (flow < k)
            cout << "Impossible" << '\n';
        else
        {
            for (int i = 0; i < k; i++)
                NoMeetPath(1, 2, graph, true);
        }
        cout << '\n';

        for (int u = 0; u < n * 2; u++)
        {
            for (Edge* edge : graph[u])
                delete edge;
        }
    }
}