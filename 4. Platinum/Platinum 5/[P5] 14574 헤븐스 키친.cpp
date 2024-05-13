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

struct Chef
{
    int p, c;
};

struct Edge
{
    int u, v;
    long long w;

    friend bool operator>(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

long long ViewRating(Chef& a, Chef& b)
{
    return (long long)(a.c + b.c) / abs(a.p - b.p);
}

int Find(int u, vector<int>& p)
{
    if (p[u] == -1)
        return u;
    return p[u] = Find(p[u], p);
}

void Union(int u, int v, vector<int>& p)
{
    p[Find(v, p)] = Find(u, p);
}

long long MaxViewRating(int n, vector<Edge>& edges, vector<vector<Edge>>& tree)
{
    sort(edges.begin(), edges.end(), greater<Edge>());

    vector<int> p(n, -1);
    long long result = 0;
    for (Edge& edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        long long w = edge.w;

        if (Find(u, p) == Find(v, p))
            continue;

        Union(u, v, p);
        result += w;
        tree[u].push_back({ -1,v,w });
        tree[v].push_back({ -1,u,w });
    }
    return result;
}

void DFS(int cur, int pre, vector<vector<Edge>>& tree)
{
    for (Edge& edge : tree[cur])
    {
        int nxt = edge.v;
        int w = edge.w;

        if (nxt == pre)
            continue;

        DFS(nxt, cur, tree);
        cout << cur + 1 << ' ' << nxt + 1 << '\n';
    }
}

void PrintMatchSchedule(vector<vector<Edge>>& tree)
{
    DFS(0, -1, tree);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Chef> chefs(n);
    for (int i = 0; i < n; i++)
        cin >> chefs[i].p >> chefs[i].c;

    vector<Edge> edges;
    for (int u = 0; u < n - 1; u++)
    {
        for (int v = u + 1; v < n; v++)
        {
            int w = ViewRating(chefs[u], chefs[v]);
            edges.push_back({ u,v,w });
        }
    }

    vector<vector<Edge>> tree(n);
    long long result = MaxViewRating(n, edges, tree);
    cout << result << '\n';
    PrintMatchSchedule(tree);
}