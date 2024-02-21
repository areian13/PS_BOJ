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

void MakeTree(int cur, vector<int>& depth, vector<int>& dist, vector<vector<int>>& tree, vector<vector<Edge>>& graph)
{
    for (Edge nxt : graph[cur])
    {
        int v = nxt.v;
        int w = nxt.w;

        if (dist[v] != -1)
            continue;

        tree[v][0] = cur;
        dist[v] = dist[cur] + w;
        depth[v] = depth[cur] + 1;
        MakeTree(v, depth, dist, tree, graph);
    }
}

int main()
{
    FastIO;

    int n;
    Cin n;

    vector<vector<Edge>> graph(n);
    For(n - 1)
    {
        int u, v, w;
        Cin u >> v >> w;
        u--, v--;

        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });
    }

    vector<int> dist(n, -1), depth(n, -1);
    dist[0] = 0;
    depth[0] = 0;

    int k = log2(n) + 1;
    vector<vector<int>> tree(n, vector<int>(k));

    MakeTree(0, depth, dist, tree, graph);

    for (int j = 1; j < k; j++)
    {
        for (int i = 1; i < n; i++)
        {
            if (tree[i][j - 1] != -1)
                tree[i][j] = tree[tree[i][j - 1]][j - 1];
        }
    }

    int m;
    Cin m;

    while (m--)
    {
        int u, v;
        Cin u >> v;
        u--, v--;

        int uDist = dist[u];
        int vDist = dist[v];

        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];
        for (int j = 0; diff > 0; j++)
        {
            if (diff % 2 == 1)
                u = tree[u][j];
            diff /= 2;
        }

        if (u != v)
        {
            for (int j = k - 1; j >= 0; j--)
            {
                if (tree[u][j] != -1 && tree[u][j] != tree[v][j])
                {
                    u = tree[u][j];
                    v = tree[v][j];
                }
            }
            u = tree[u][0];
        }
        int result = uDist + vDist - dist[u] * 2;
        Cout result Endl;
    }
}