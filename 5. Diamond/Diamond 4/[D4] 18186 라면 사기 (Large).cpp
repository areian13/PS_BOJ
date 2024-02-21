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

int main()
{
    FastIO;

    LLONG n, b, c;
    Cin n >> b >> c;

    vector<int> a(n);
    For(n)
        Cin a[i];

    LLONG result = 0;
    For(n)
    {
        if (b > c)
        {
            if (i < n - 2 && a[i + 1] > a[i + 2])
            {
                LLONG k2 = min(a[i], a[i + 1] - a[i + 2]);
                a[i] -= k2;
                a[i + 1] -= k2;
                result += k2 * (b + c);

                LLONG k3 = min({ a[i], a[i + 1], a[i + 2] });
                a[i] -= k3;
                a[i + 1] -= k3;
                a[i + 2] -= k3;
                result += k3 * (b + 2 * c);
            }
            elif(i < n - 2 && a[i + 1] <= a[i + 2])
            {
                LLONG k3 = min(a[i], a[i + 1]);
                a[i] -= k3;
                a[i + 1] -= k3;
                a[i + 2] -= k3;
                result += k3 * (b + 2 * c);
            }
            elif(i < n - 1)
            {
                LLONG k2 = min(a[i], a[i + 1]);
                a[i] -= k2;
                a[i + 1] -= k2;
                result += k2 * (b + c);
            }
        }
        
        result += a[i] * b;
    }
    Cout result Endl;
}