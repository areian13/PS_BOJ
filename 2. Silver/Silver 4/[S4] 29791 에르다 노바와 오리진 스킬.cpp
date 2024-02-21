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

#define TIME 1'000'000

array<array<bool, TIME + 1>, 2> isPushed = { false, };

int main()
{
    FastIO;

    int n, m;
    Cin n >> m;

    array<int, 2> cnt = { n,m };
    For(2)
    {
        Forj(cnt[i])
        {
            int pushTime;
            Cin pushTime;

            isPushed[i][pushTime] = true;
        }
    }

    array<int, 2> curCoolTime = { 0,0 };
    array<int, 2> skillCoolTime = { 100,360 };
    array<int, 2> result = { 0,0 };
    Foro(TIME)
    {
        Forj(2)
        {
            if (isPushed[j][i])
            {
                if (curCoolTime[j] == 0)
                {
                    result[j]++;
                    curCoolTime[j] = skillCoolTime[j];
                }
            }
            curCoolTime[j] = max(curCoolTime[j] - 1, 0);
        }
    }
    Cout result Endl;
}