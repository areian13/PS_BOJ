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
    int z, y, x;
};

array<int, 6> dz = { 0,0,1,0,0,-1 };
array<int, 6> dy = { 0,1,0,0,-1,0 };
array<int, 6> dx = { 1,0,0,-1,0,0 };

int RipeningDay(vector<vector<vector<int>>>& tomato, vector<vector<vector<int>>>& dist, queue<Pos>& Q)
{
    int h = tomato.size();
    int n = tomato[0].size();
    int m = tomato[0][0].size();

    while (!Q.empty())
    {
        int z = Q.front().z;
        int y = Q.front().y;
        int x = Q.front().x;
        Q.pop();

        For(6)
        {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (tomato[nz][ny][nx] == -1 || dist[nz][ny][nx] != -1)
                continue;

            dist[nz][ny][nx] = dist[z][y][x] + 1;
            Q.push({ nz,ny,nx });
        }
    }

    int result = 0;
    For(h)
    {
        Forj(n)
        {
            for (int k = 0; k < m; k++)
            {
                if (tomato[i][j][k] != -1 && dist[i][j][k] == -1)
                    return -1;

                result = max(result, dist[i][j][k]);
            }
        }
    }
    return result;
}

int main()
{
    FastIO;

    int m, n, h;
    Cin m >> n >> h;

    vector<vector<vector<int>>> tomato(h, vector<vector<int>>(n, vector<int>(m)));
    vector<vector<vector<int>>> dist(h, vector<vector<int>>(n, vector<int>(m, -1)));
    queue<Pos> Q;
    For(h)
    {
        Forj(n)
        {
            for (int k = 0; k < m; k++)
            {
                Cin tomato[i][j][k];

                if (tomato[i][j][k] == 1)
                {
                    dist[i][j][k] = 0;
                    Q.push({ i,j,k });
                }
            }
        }
    }

    int result = RipeningDay(tomato, dist, Q);
    Cout result Endl;
}