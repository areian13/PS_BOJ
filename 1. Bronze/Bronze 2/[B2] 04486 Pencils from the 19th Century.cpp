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

    int t = 0;
    while (true)
    {
        int n;
        Cin n;

        if (n == 0)
            break;
        
        bool canBuy = false;
        printf("Case %d:\n%d pencils for %d cents\n", ++t, n, n);
        
        vector<array<int, 3>> result;
        for (int j = 1; j * 0.5 <= n; j++)
        {
            for (int k = 1; j * 0.5 + k * 0.25 <= n; k++)
            {
                int i = j / 6.0 + k / 4.0;
                if (i + j + k == n && i * 4 + j * 0.5 + k * 0.25 == n)
                    result.push_back({ i,j,k });
            }
        }
        reverse(stoe(result));

        if (result.empty())
            printf("No solution found.\n\n");
        else
        {
            for (array<int, 3>& value : result)
            {
                printf("%d at four cents each\n", value[0]);
                printf("%d at two for a penny\n", value[1]);
                printf("%d at four for a penny\n\n", value[2]);
            }
        }
    }
}