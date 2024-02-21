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

int Normalize(int v)
{
    if (v == 0)
        return 0;
    return v / abs(v);
}

int SegTree(int start, int end, int idx, int l, int r, vector<int>& x)
{
    if (r < start || end < l)
        return 1;
    if (start <= l && r <= end)
        return x[idx];

    int mid = (l + r) / 2;
    return SegTree(start, end, idx * 2, l, mid, x)
        * SegTree(start, end, idx * 2 + 1, mid + 1, r, x);
}

int main()
{
    FastIO;

    while (true)
    {
        int n, k;
        Cin n >> k;

        if (cin.eof())
            break;

        int r = log2(2 * n - 1);
        int size = 1 << r;

        vector<int> x(2 * size, 1);
        For(n)
        {
            int v;
            Cin v;

            x[size + i] = Normalize(v);
        }
        for (int i = size - 1; i > 0; i--)
            x[i] = x[i * 2] * x[i * 2 + 1];

        string result = "";
        while (k--)
        {
            char c;
            Cin c;

            if (c == 'C')
            {
                int i, v;
                Cin i >> v;

                i += size - 1;
                x[i] = Normalize(v);
                while (i > 1)
                {
                    i /= 2;
                    x[i] = x[i * 2] * x[i * 2 + 1];
                }
            }
            else
            {
                int i, j;
                Cin i >> j;
                i--, j--;

                int mul = SegTree(i, j, 1, 0, size - 1, x);
                result += (mul == 0 ? '0' : (mul > 0 ? '+' : '-'));
            }
        }
        Cout result Endl;
    }
}