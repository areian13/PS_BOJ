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

using namespace std;

template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T>>
{
};

int CountBluray(int limit, int m, vector<int>& lecture)
{
    int cnt = 1;
    int sum = 0;

    int n = lecture.size();
    for (int i = 0; i < n; i++)
    {
        if (sum + lecture[i] <= limit)
            sum += lecture[i];
        elif(sum + lecture[i] > limit)
        {
            cnt++;
            sum = lecture[i];
        }
    }
    return cnt;
}

int main()
{
    FastIO;

    int n, m;
    Cin n >> m;

    vector<int> lecture(n);
    For(n)
        Cin lecture[i];

    int start = *max_element(stoe(lecture));
    int end = accumulate(stoe(lecture), 0);
    int result = INT_MAX;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int cnt = CountBluray(mid, m, lecture);
        if (cnt > m)
            start = mid + 1;
        elif(cnt <= m)
        {
            result = mid;
            end = mid - 1;
        }
    }
    Cout result Endl;
}