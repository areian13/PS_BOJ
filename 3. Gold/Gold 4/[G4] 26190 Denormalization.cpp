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

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int ListGCD(vector<int>& list)
{
    if (list.empty())
        return 1;

    int gcd = list[0];
    for (int e : list)
        gcd = GCD(gcd, e);
    return gcd;
}

int main()
{
    FastIO;

    int n;
    Cin n;

    vector<double> x(n);
    double minX = 1;
    For(n)
    {
        Cin x[i];
        minX = min(minX, x[i]);
    }

    double maxX = 0;
    For(n)
    {
        x[i] /= minX;
        maxX = max(maxX, x[i]);
    }

    int d = 0;
    double minDiff = 1;
    for (int tempD = 1; (int)(tempD * maxX + 0.5) <= 10'000; tempD++)
    {
        double diff = 0;
        For(n)
            diff = max(diff, abs((int)(tempD * x[i] + 0.5) - tempD * x[i]));

        if (diff < minDiff)
        {
            minDiff = diff;
            d = tempD;
        }
    }

    vector<int> r(n);
    For(n)
        r[i] = x[i] * d + 0.5;

    int gcd = ListGCD(r);
    For(n)
    {
        r[i] /= gcd;
        Cout r[i] Endl;
    }
}