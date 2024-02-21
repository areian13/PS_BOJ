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

int main()
{
    FastIO;

    array<vector<LLONG>, 50> a =
    { vector<LLONG>
        {0, 0, 0},
        {0, 0, 1},
        {0, 1, 1},
        {1, 1, 1},
        {0},
        {0},
        {-1, -1, 2},
        {0, -1, 2},
        {0, 0, 2},
        {0, 1, 2},
        {1, 1, 2},
        {-2, -2, 3},
        {7, 10, -11},
        {0},
        {0},
        {-1, 2, 2},
        {-511, -1609, 1626},
        {1, 2, 2},
        {-1, -2, 3},
        {0, -2, 3},
        {1, -2, 3},
        {-11, -14, 16},
        {0},
        {0},
        {-2901096694, -15550555555, 15584139827},
        {-1, -1, 3},
        {0, -1, 3},
        {0, 0, 3},
        {0, 1, 3},
        {1, 1, 3},
        {-283059965, -2218888517, 2220422932},
        {0},
        {0},
        {8866128975287528, -8778405442862239, -2736111468807040},
        {-1, 2, 3},
        {0, 2, 3},
        {1, 2, 3},
        {0, -3, 4},
        {1, -3, 4},
        {117367, 134476, -159380},
        {0},
        {0},
        {-80538738812075974, 80435758145817515, 12602123297335631},
        {2, 2, 3},
        {-5, -7, 8},
        {2, -3, 4},
        {-2, 3, 3},
        {6, 7, -8},
        {-23, -26, 31},
        {0},
    };

    int n;
    Cin n;

    if (a[n].size() == 1)
        Cout a[n][0] Endl;
    else
        Cout a[n][0] spc a[n][1] spc a[n][2] Endl;
}
// 뒤에 공백 문자가 존재하면 틀렸다고 판단한다. 
// 이는 문제의 문제이므로 추후 테스트 케이스가 수정되면 다시 작성하겠다.