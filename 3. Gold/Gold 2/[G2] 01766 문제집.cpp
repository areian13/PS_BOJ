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

struct Order
{
    int num, indegree;

    friend bool operator<(const Order& a, const Order& b)
    {
        if (a.indegree == 0 && b.indegree == 0)
            return a.num > b.num;
        return a.indegree > b.indegree;
    }
};

int main()
{
    FastIO;

    int n, m;
    Cin n >> m;

    vector<vector<int>> graph(n);
    vector<Order> order(n);
    For(m)
    {
        int a, b;
        Cin a >> b;
        a--, b--;

        order[b].indegree++;
        graph[a].push_back(b);
    }

    priority_queue<Order> PQ;
    For(n)
    {
        order[i].num = i;
        PQ.push(order[i]);
    }

    vector<int> result;
    vector<bool> isPushed(n, false);
    while (!PQ.empty())
    {
        int cur = PQ.top().num;
        PQ.pop();

        if (isPushed[cur])
            continue;

        result.push_back(cur + 1);
        isPushed[cur] = true;
        for (int nxt : graph[cur])
        {
            order[nxt].indegree--;

            if (order[nxt].indegree == 0)
                PQ.push(order[nxt]);
        }
    }
    Cout result Endl;
}