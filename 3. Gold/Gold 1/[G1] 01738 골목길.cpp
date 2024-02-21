#ifdef ONLINE_JUDGE
#define _128d  __int128
#else
#define _128d long long
#endif

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
#include <cfloat>
#include <cstring>
#include <random>
#include <type_traits>
#include <numeric>
#include <functional>

#define Endl << "\n"
#define endL << "\n" <<
#define Cout cout <<
#define COUT cout << "OUT: " <<
#define Cin cin >>
#define fspc << " "
#define spc << " " <<
#define Enter cout << "\n"
#define if if
#define elif else if
#define else else
#define For(n) for(int i = 0; i < n; i++)
#define Forj(n) for(int j = 0; j < n; j++)
#define Foro(n) for(int i = 1; i <= n; i++)
#define Forjo(n) for(int j = 1; j <= n; j++)
#define between(small, middle, big) (small < middle && middle < big)
#define among(small, middle, big) (small <= middle && middle <= big)
#define stoe(container) container.begin(), container.end()
#define lf(d) Cout fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI 3.14159265359

typedef long long LLONG;
typedef unsigned long long ULLONG;
typedef unsigned int UINT;
typedef long double LDOUBLE;

using namespace std;

template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T>>
{
};

template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec)
{
    for (T& value : vec)
        os << value << ' ';
    return os;
}

template <typename T, size_t N>
ostream& operator<<(ostream& os, array<T, N>& vec)
{
    for (T& value : vec)
        os << value << ' ';
    return os;
}

struct Edge
{
    int u, v, w;
};

void BFS(int start, vector<bool>& isVisited, vector<vector<int>>& graph)
{
    int n = isVisited.size() - 1;

    isVisited[start] = true;

    queue<int> Q;
    Q.push(start);

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        for (int nxt : graph[cur])
        {
            if (isVisited[nxt])
                continue;

            isVisited[nxt] = true;
            Q.push(nxt);
        }
    }
}

bool BF(vector<int>& dist, vector<int>& pre, vector<Edge> edges)
{
    int n = dist.size() - 1;

    For(n)
    {
        for (Edge& edge : edges)
        {
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;

            if (dist[u] != INT_MIN && dist[v] < dist[u] + w)
            {
                if (i == n - 1)
                    return false;

                dist[v] = dist[u] + w;
                pre[v] = u;
            }
        }
    }
    return dist[n] != INT_MIN;
}

int main()
{
    FastIO;

    int n, m;
    Cin n >> m;

    vector<Edge> tempEdges(m);
    vector<vector<int>> startGraph(n + 1);
    vector<vector<int>> endGraph(n + 1);
    For(m)
    {
        int u, v, w;
        Cin u >> v >> w;

        tempEdges[i] = { u,v,w };
        startGraph[u].push_back(v);
        endGraph[v].push_back(u);
    }

    vector<bool> startIsVisited(n + 1, false);
    BFS(1, startIsVisited, startGraph);

    vector<bool> endIsVisited(n + 1, false);
    BFS(n, endIsVisited, endGraph);

    vector<Edge> edges;
    for (Edge& edge : tempEdges)
    {
        if (startIsVisited[edge.u] && startIsVisited[edge.v]
            && endIsVisited[edge.u] && endIsVisited[edge.v])
            edges.push_back(edge);
    }

    vector<int> dist(n + 1, INT_MIN);
    dist[1] = 0;
    
    vector<int> pre(n + 1);
    pre[1] = 0;

    bool canGo = BF(dist, pre, edges);

    vector<int> result;
    if (!canGo)
        result.push_back(-1);
    else
    {
        int x = n;
        while (x != 0)
        {
            result.push_back(x);
            x = pre[x];
        }
        reverse(stoe(result));
    }
    Cout result Endl;
}