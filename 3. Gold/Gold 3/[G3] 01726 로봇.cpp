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

struct Pos
{
    int y, x, d;

    friend istream& operator>>(istream& is, Pos& p)
    {
        is >> p.y >> p.x >> p.d;
        return is;
    }
};

array<int, 4> dy = { 0,0,1,-1 };
array<int, 4> dx = { 1,-1,0,0 };

int CountTurn(int d, int i)
{
    if (i == 0)
        return 0;

    return (d % 2 == 0 && i == 1) || (d % 2 == 1 && i == 3) ? 2 : 1;
}

int main()
{
    FastIO;

    int n, m;
    Cin n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    For(n)
    {
        Forj(m)
            Cin map[i][j];
    }
    Pos s, e;
    Cin s >> e;
    s.y--; s.x--; s.d--;
    e.y--; e.x--; e.d--;

    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(4, -1)));
    dist[s.y][s.x][s.d] = 0;
    
    queue<Pos> Q;
    Q.push(s);

    while (!Q.empty())
    {
        int y = Q.front().y;
        int x = Q.front().x;
        int d = Q.front().d;
        Q.pop();

        Foro(3)
        {
            int nd = (d + i) % 4;
            int ndis = dist[y][x][d] + CountTurn(d, i);
            if (dist[y][x][nd] != -1 && dist[y][x][nd] <= ndis)
                continue;

            dist[y][x][nd] = ndis;
            Q.push({ y,x,nd });
        }

        Foro(3)
        {
            int ny = y + dy[d] * i;
            int nx = x + dx[d] * i;

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (dist[ny][nx][d] != -1 && dist[ny][nx][d] <= dist[y][x][d] + 1)
                continue;
            if (map[ny][nx] == 1)
                break;

            dist[ny][nx][d] = dist[y][x][d] + 1;
            Q.push({ ny,nx,d });
        }
    }

    int result = dist[e.y][e.x][e.d];
    Cout result Endl;
}