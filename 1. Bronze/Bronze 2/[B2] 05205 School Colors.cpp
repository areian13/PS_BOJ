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

struct RGB
{
    int r, g, b;

    friend double operator-(const RGB & a, const RGB & b)
    {
        return sqrt(pow(a.r - b.r, 2) + pow(a.g - b.g, 2) + pow(a.b - b.b, 2));
    }
};

int main()
{
    FastIO;

    int tc;
    Cin tc;

    for (int t = 1; t <= tc; t++)
    {
        int n;
        Cin n;

        vector<RGB> rgb(n);
        For(n)
        {
            int r, g, b;
            Cin r >> g >> b;

            rgb[i] = { r,g,b };
        }

        double maxDiff = 0;
        For(n)
        {
            for (int j = i + 1; j < n; j++)
                maxDiff = max(maxDiff, rgb[i] - rgb[j]);
        }

        vector<array<int, 2>> result;
        For(n)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (maxDiff == rgb[i] - rgb[j])
                    result.push_back({ i + 1,j + 1 });
            }
        }

        printf("Data Set %d:\n", t);
        for (array<int, 2>& idx : result)
            printf("%d %d\n", idx[0], idx[1]);
    }
}