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
    int v, w;
};

void MakeTree(int cur, vector<int>& depth, vector<int>& dist,
    vector<vector<int>>& tree, vector<vector<Edge>>& graph)
{
    for (Edge& nxt : graph[cur])
    {
        int v = nxt.v;
        int w = nxt.w;

        if (depth[v] != -1)
            continue;

        depth[v] = depth[cur] + 1;
        dist[v] = dist[cur] + w;
        tree[v][0] = cur;
        MakeTree(v, depth, dist, tree, graph);
    }
}
int main()
{
    FastIO;

    int n;
    Cin n;

    vector<int> ant(n);
    For(n)
        Cin ant[i];

    vector<vector<Edge>> graph(n);
    For(n - 1)
    {
        int u, v, w;
        Cin u >> v >> w;
        u--, v--;

        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });
    }

    vector<int> depth(n, -1);
    depth[0] = 0;
    vector<int> dist(n, -1);
    dist[0] = 0;

    int k = log2(n) + 1;
    vector<vector<int>> tree(n, vector<int>(k, -1));
    MakeTree(0, depth, dist, tree, graph);

    for (int j = 1; j < k; j++)
    {
        for (int i = 1; i < n; i++)
        {
            if (tree[i][j - 1] != -1)
                tree[i][j] = tree[tree[i][j - 1]][j - 1];
        }
    }

    For(n)
    {
        int u = i;
        int uDist = dist[u];
        int uDepth = depth[u];
        for (int j = k - 1; j >= 0; j--)
        {
            if (uDepth >= 1 << j)
            {
                int tempU = tree[u][j];
                if (uDist - dist[tempU] > ant[i])
                    continue;
                uDepth -= 1 << j;
                u = tree[u][j];
            }
        }

        int result = u + 1;
        Cout result Endl;
    }
}