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

struct Pos
{
    int y, x;
};

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,1,0,-1 };

int RipeningDay(vector<vector<int>>& tomato, vector<vector<int>>& dist, queue<Pos>& Q)
{
    int n = tomato.size();
    int m = tomato[0].size();

    while (!Q.empty())
    {
        int y = Q.front().y;
        int x = Q.front().x;
        Q.pop();

        For(4)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (tomato[ny][nx] == -1 || dist[ny][nx] != -1)
                continue;

            dist[ny][nx] = dist[y][x] + 1;
            Q.push({ ny,nx });
        }
    }

    int result = 0;
    For(n)
    {
        Forj(m)
        {
            if (tomato[i][j] != -1 && dist[i][j] == -1)
                return -1;

            result = max(result, dist[i][j]);
        }
    }
    return result;
}

int main()
{
    FastIO;

    int m, n;
    Cin m >> n;

    vector<vector<int>> tomato(n, vector<int>(m));
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<Pos> Q;
    For(n)
    {
        Forj(m)
        {
            Cin tomato[i][j];

            if (tomato[i][j] == 1)
            {
                dist[i][j] = 0;
                Q.push({ i,j });
            }
        }
    }

    int result = RipeningDay(tomato, dist, Q);
    Cout result Endl;
}