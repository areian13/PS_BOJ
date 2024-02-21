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

void Spin(string& footprint)
{
    char temp = footprint[0];
    footprint[0] = footprint[2];
    footprint[2] = footprint[3];
    footprint[3] = footprint[1];
    footprint[1] = temp;
}
int main()
{
    FastIO;

    unordered_map<string, string> UMP;
    UMP[".OP."] = "T";
    UMP["I..P"] = "F";
    UMP["O..P"] = "Lz";

    char dir;
    Cin dir;

    string footprint;
    For(4)
    {
        char foot;
        Cin foot;

        footprint += foot;
    }

    string senw = "SENW";
    int cnt = 0;
    while (senw[cnt] != dir)
        cnt++;

    For(cnt)
        Spin(footprint);

    string result = (UMP[footprint] != "" ? UMP[footprint] : "?");
    Cout result Endl;
}
