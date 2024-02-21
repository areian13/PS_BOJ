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

struct JH
{
    array<int, 2> jh;

    friend JH operator+(const JH& a, const JH& b)
    {
        return { a.jh[0] + b.jh[0],a.jh[1] + b.jh[1] };
    }
};

JH JHlize(int x)
{
    bool isJ = (x % 2 == 0);
    return { isJ,!isJ };
}

JH SegTree(int start, int end, int idx, int l, int r, vector<JH>& a)
{
    if (r < start || end < l)
        return { 0,0 };
    if (start <= l && r <= end)
        return a[idx];
    
    int mid = (l + r) / 2;
    return SegTree(start, end, idx * 2, l, mid, a)
        + SegTree(start, end, idx * 2 + 1, mid + 1, r, a);
}

int main()
{
    FastIO;

    int n;
    Cin n;

    int r = log2(2 * n - 1);
    int size = 1 << r;

    vector<JH> a(2 * size, { 0,0 });
    For(n)
    {
        int x;
        Cin x;

        a[size + i] = JHlize(x);
    }
    for (int i = size - 1; i > 0; i--)
        a[i] = a[i * 2] + a[i * 2 + 1];

    int m;
    Cin m;

    while (m--)
    {
        int c;
        Cin c;

        if (c == 1)
        {
            int i, x;
            Cin i >> x;

            i += size - 1;
            a[i] = JHlize(x);
            while (i > 1)
            {
                i /= 2;
                a[i] = a[i * 2] + a[i * 2 + 1];
            }
        }
        else
        {
            int l, r;
            Cin l >> r;
            l--, r--;

            JH result = SegTree(l, r, 1, 0, size - 1, a);
            Cout result.jh[c - 2] Endl;
        }
    }
}