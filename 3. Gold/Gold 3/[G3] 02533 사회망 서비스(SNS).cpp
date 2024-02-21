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
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <limits.h>
#include <float.h>
#include <string.h>
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

void MakeTree(int cur, vector<bool>& isUsed, vector<vector<int>>& tree, vector<vector<int>>& graph)
{
    isUsed[cur] = true;

    for (int nxt : graph[cur])
    {
        if (isUsed[nxt])
            continue;

        tree[cur].push_back(nxt);
        MakeTree(nxt, isUsed, tree, graph);
    }
}

int SNS(int cur, bool wasEarlier, vector<array<int, 2>>& dp, vector<vector<int>>& tree)
{
    int& result = dp[cur][wasEarlier];
    if (result != -1)
        return result;

    array<int, 2> cnt = { INT_MAX * !wasEarlier,1 };
    for (int nxt : tree[cur])
        cnt[1] += SNS(nxt, true, dp, tree);

    if (wasEarlier)
    {
        for (int nxt : tree[cur])
            cnt[0] += SNS(nxt, false, dp, tree);
    }

    return result = min(cnt[0], cnt[1]);
}

int main()
{
    FastIO;

    int n;
    Cin n;

    vector<vector<int>> graph(n + 1), tree(n + 1);
    For(n - 1)
    {
        int u, v;
        Cin u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> isUsed(n + 1, false);
    MakeTree(1, isUsed, tree, graph);

    vector<array<int, 2>> dp(n + 1, { -1,-1 });
    int result = SNS(1, true, dp, tree);
    Cout result Endl;
}