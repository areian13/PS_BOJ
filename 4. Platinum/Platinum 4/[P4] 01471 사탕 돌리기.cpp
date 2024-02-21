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

int SumDigit(int n)
{
    int result = 0;
    while (n > 0)
    {
        result += n % 10;
        n /= 10;
    }
    return result;
}

vector<int> nthDFS, nthSCC, cntNthSCC;
vector<bool> isFinished;
stack<int> S;

int cntDFS = 0, cntSCC = 0;

int DFS(int cur)
{
    nthDFS[cur] = ++cntDFS;
    S.push(cur);

    int n = nthDFS.size() - 1;
    int nxt = (cur + SumDigit(cur) - 1) % n + 1;

    int result = nthDFS[cur];
    if (nthDFS[nxt] == 0)
        result = min(result, DFS(nxt));
    elif(!isFinished[nxt])
        result = min(result, nthDFS[nxt]);

    if (result == nthDFS[cur])
    {
        cntSCC++;
        while (true)
        {
            int t = S.top();
            S.pop();

            nthSCC[t] = cntSCC;
            isFinished[t] = true;

            if (t == cur)
                break;
        }
    }
    return result;
}

vector<int> dp;

int DP(int cur)
{
    if (dp[cur] != 0)
        return dp[cur];

    dp[cur] = cntNthSCC[nthSCC[cur]];

    int n = dp.size() - 1;
    int nxt = (cur + SumDigit(cur) - 1) % n + 1;
    if (nthSCC[nxt] != nthSCC[cur])
        dp[cur] += DP(nxt);
    return dp[cur];
}

int main()
{
    FastIO;

    int n;
    Cin n;

    nthDFS.resize(n + 1, 0);
    nthSCC.resize(n + 1, 0);
    isFinished.resize(n + 1, false);

    Foro(n)
    {
        if (nthDFS[i] == 0)
            DFS(i);
    }

    cntNthSCC.resize(cntSCC + 1);
    Foro(n)
        cntNthSCC[nthSCC[i]]++;

    dp.resize(n + 1, 0);
    int result = 0;
    Foro(n)
        result = max(result, DP(i));
    Cout result Endl;
}