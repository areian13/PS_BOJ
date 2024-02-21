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
    int y, x;
};

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { -1,0,1,0, };

bool IsAdjacented(int cur, int n, int m)
{
    vector<vector<int>> map(n, vector<int>(n, '.'));
    Pos s;
    For(n)
    {
        Forj(n)
        {
            if (cur & (1 << i * n + j))
            {
                map[i][j] = '*';
                s = { i,j };
            }
        }
    }

    vector<vector<bool>> isVisited(n, vector<bool>(n, false));
    isVisited[s.y][s.x] = true;
    
    queue<Pos> Q;
    Q.push(s);

    int cnt = 1;
    while (!Q.empty())
    {
        int y = Q.front().y;
        int x = Q.front().x;
        Q.pop();

        For(4)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;
            if (isVisited[ny][nx] || map[ny][nx] == '.')
                continue;

            cnt++;
            isVisited[ny][nx] = true;
            Q.push({ ny,nx });
        }
    }
    return (cnt == m);
}

int main()
{
    FastIO;

    int n = 5;
    
    int m = 0;
    int s = 0;
    For(n)
    {
        Forj(n)
        {
            char map;
            Cin map;

            if (map == '*')
            {
                m++;
                s |= (1 << i * n + j);
            }
        }
    }

    vector<int> dist(1 << n * n, -1);
    dist[s] = 0;

    queue<int> Q;
    Q.push(s);

    int result = 0;
    while (!Q.empty())
    {
        int state = Q.front();
        Q.pop();

        if (IsAdjacented(state, n, m))
        {
            result = dist[state];
            break;
        }

        For(1 << n)
        {
            if (!(state & (1 << i)))
                continue;

            int y = i / n;
            int x = i % n;

            int cur = (1 << y * n + x);

            Forj(4)
            {
                int ny = y + dy[j];
                int nx = x + dx[j];

                if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                    continue;

                int nxt = (1 << ny * n + nx);
                if (state & nxt || dist[state & ~cur | nxt] != -1)
                    continue;

                dist[state & ~cur | nxt] = dist[state] + 1;
                Q.push(state & ~cur | nxt);
            }
        }
    }
    Cout result Endl;
}