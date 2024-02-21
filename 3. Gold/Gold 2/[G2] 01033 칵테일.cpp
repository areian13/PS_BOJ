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

struct Ratio
{
    int a, b, p, q;
};

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int ArrayGCD(vector<int>& arr)
{
    int n = arr.size();

    int result = arr[0];
    for (int i = 1; i < n; i++)
        result = GCD(result, arr[i]);
    return result;
}

void DFS(int u, int p, vector<bool>& isVisited, vector<int>& result, vector<vector<int>>& graph)
{
    isVisited[u] = true;
    result[u] *= p;
    
    for (int v : graph[u])
    {
        if (isVisited[v])
            continue;

        DFS(v, p, isVisited, result, graph);
    }
}

int main()
{
    FastIO;

    int n;
    Cin n;

    vector<vector<int>> graph(n);
    vector<Ratio> ratio(n - 1);
    For(n - 1)
    {
        int a, b, p, q;
        Cin a >> b >> p >> q;

        ratio[i] = { a,b,p,q };
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> result(n, 1);
    For(n - 1)
    {
        vector<bool> isVisited(n, false);

        Ratio& r = ratio[i];
        
        isVisited[r.b] = true;
        DFS(r.a, r.p, isVisited, result, graph);

        isVisited[r.b] = false;
        DFS(r.b, r.q, isVisited, result, graph);
    }

    int gcd = ArrayGCD(result);
    For(n)
        result[i] /= gcd;
    Cout result Endl;
}