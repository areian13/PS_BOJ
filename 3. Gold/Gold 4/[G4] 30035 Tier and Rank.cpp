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

struct Tier
{
    int total;
    array<int, 4> detail;
};

int main()
{
    FastIO;

    int n, t;
    Cin n >> t;

    vector<Tier> tier(t + 1);
    unordered_map<string, int> tierGrade;
    int m = n;
    Foro(t)
    {
        string tierName, k;
        Cin tierName >> k;

        tierGrade[tierName] = i;

        int l = 0;
        if (k.back() == '%')
        {
            k.pop_back();
            l = (LLONG)m * stoi(k) / 100;
        }
        else
            l = min(m, stoi(k));

        tier[i].total = l;
        m -= l;

        int detail = ceill(l / 4.0);
        Forj(4)
            tier[i].detail[j] = min(detail, max(l - detail * j, 0));
    }
    string friendTier;
    Cin friendTier;

    if (m != 0)
        Cout "Invalid System" Endl;
    else
    {
        int bigTier = 0;
        int smallTier = -1;

        if (among('1', friendTier.back(), '4'))
        {
            smallTier = friendTier.back() - '1';
            friendTier.pop_back();
        }
        bigTier = tierGrade[friendTier];

        if (bigTier == 0
            || (smallTier == -1 && tier[bigTier].total == 0)
            || (smallTier != -1 && tier[bigTier].detail[smallTier] == 0))
            Cout "Liar" Endl;
        else
        {
            int top = 0;
            for (int i = 1; i < bigTier; i++)
                top += tier[i].total;

            int bottom = top;
            if (smallTier == -1)
                bottom += tier[bigTier].total;
            else
            {
                for (int i = 0; i < smallTier; i++)
                    top += tier[bigTier].detail[i];
                bottom = top + tier[bigTier].detail[smallTier];
            }
            top++;
            Cout top spc bottom Endl;
        }
    }
}