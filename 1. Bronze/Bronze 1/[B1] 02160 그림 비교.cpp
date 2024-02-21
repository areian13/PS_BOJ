#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
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

#define Endl << "\n"
#define endL << "\n" <<
#define Cout cout <<
#define	COUT cout << "OUT: " <<
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
#define ulf cout.unsetf(ios::scientific);
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI 3.14159265359

typedef long long LLONG;
typedef unsigned long long ULLONG;
typedef unsigned int UINT;

using namespace std;

template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T>>
{
};

int CountGap(array<array<char, 7>, 5>& a, array<array<char, 7>, 5>& b)
{
    int result = 0;
    For(5)
    {
        Forj(7)
            result += (a[i][j] != b[i][j]);
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    Cin n;

    vector<array<array<char, 7>, 5>> drawing(n);
    for (int k = 0; k < n; k++)
    {
        For(5)
        {
            Forj(7)
                Cin drawing[k][i][j];
        }
    }

    int minGap = INT_MAX;
    int l, r;
    For(n)
    {
        for (int j = i + 1; j < n; j++)
        {
            int gap = CountGap(drawing[i], drawing[j]);
            if (gap < minGap)
            {
                minGap = gap;
                l = i + 1;
                r = j + 1;
            }
        }
    }
    Cout l spc r Endl;
}