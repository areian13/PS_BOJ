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

vector<vector<int>> graph;
vector<int> nthDFS, nthSCC, SCCCost;
vector<bool> isFinished;
stack<int> S;

int cntDFS = 0, cntSCC = 0;

int DFS(int cur)
{
    nthDFS[cur] = ++cntDFS;
    S.push(cur);

    int result = nthDFS[cur];
    for (int nxt : graph[cur])
    {
        if (nthDFS[nxt] == 0)
            result = min(result, DFS(nxt));
        elif(!isFinished[nxt])
            result = min(result, nthDFS[nxt]);
    }

    if (result == nthDFS[cur])
    {
        int cost = 0;
        while (true)
        {
            int t = S.top();
            S.pop();

            isFinished[t] = true;
            nthSCC[t] = cntSCC;
            cost++;

            if (t == cur)
                break;
        }
        cntSCC++;
        SCCCost.push_back(cost);
    }
    return result;
}

int main()
{
    FastIO;

    int n, m, s, t;
    Cin n >> m >> s >> t;
    s--, t--;

    graph.resize(n);
    For(m)
    {
        int a, b;
        Cin a >> b;
        a--, b--;

        graph[a].push_back(b);
    }

    nthDFS.resize(n);
    nthSCC.resize(n);
    isFinished.resize(n);
    For(n)
    {
        if (nthDFS[i] == 0)
            DFS(i);
    }

    vector<int> indegree(cntSCC, 0);
    vector<vector<int>> SCCGraph(cntSCC);
    vector<vector<bool>> isConnected(cntSCC, vector<bool>(cntSCC, false));
    For(n)
    {
        for (int nxt : graph[i])
        {
            if (nthSCC[i] != nthSCC[nxt] && !isConnected[nthSCC[i]][nthSCC[nxt]])
            {
                isConnected[nthSCC[i]][nthSCC[nxt]] = true;
                indegree[nthSCC[nxt]]++;
                SCCGraph[nthSCC[i]].push_back(nthSCC[nxt]);
            }
        }
    }

    queue<int> Q;
    For(cntSCC)
    {
        if (indegree[i] == 0)
            Q.push(i);
    }

    vector<int> dist(cntSCC, 0);
    dist[nthSCC[s]] = SCCCost[nthSCC[s]];

    vector<bool> canVisited(cntSCC, false);
    canVisited[nthSCC[s]] = true;
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        for (int nxt : SCCGraph[cur])
        {
            if (canVisited[cur])
            {
                dist[nxt] = max(dist[nxt], dist[cur] + SCCCost[nxt]);
                canVisited[nxt] = true;
            }

            indegree[nxt]--;
            if (indegree[nxt] == 0)
                Q.push(nxt);
        }
    }

    int result = dist[nthSCC[t]];
    Cout result Endl;
}