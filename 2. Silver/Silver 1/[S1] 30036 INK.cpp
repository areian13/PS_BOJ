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

int Dir(char dir)
{
    if (dir == 'D')
        return 0;
    if (dir == 'R')
        return 1;
    if (dir == 'U')
        return 2;
    return 3;
}

void Move(Pos& s, char dir, vector<vector<char>>& map)
{
    int n = map.size();

    int idx = Dir(dir);

    int ny = s.y + dy[idx];
    int nx = s.x + dx[idx];

    if (ny < 0 || ny >= n || nx < 0 || nx >= n)
        return;
    if (map[ny][nx] != '.')
        return;

    map[s.y][s.x] = '.';
    map[ny][nx] = '@';
    s = { ny,nx };
}

void Jump(Pos& s, int c, int m, vector<vector<char>>& map)
{
    int n = map.size();

    for (int a = -m; a <= m; a++)
    {
        for (int b = -m; b <= m; b++)
        {
            if (abs(a) + abs(b) > m)
                continue;

            int ny = s.y + a;
            int nx = s.x + b;

            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;

            if (map[ny][nx] != '.' && map[ny][nx] != '@')
                map[ny][nx] = c;
        }
    }
}

int main()
{
    FastIO;

    int i, n, k;
    string ink;
    Cin i >> n >> k >> ink;

    vector<vector<char>> map(n, vector<char>(n));
    Pos s;
    For(n)
    {
        Forj(n)
        {
            Cin map[i][j];
            if (map[i][j] == '@')
                s = { i,j };
        }
    }
    string cmdLine;
    Cin cmdLine;

    int m = 0;
    int cntJump = 0;

    for (char cmd : cmdLine)
    {
        if (cmd == 'j')
            m++;
        elif(cmd == 'J')
        {
            char c = ink[cntJump % i];
            cntJump++;

            Jump(s, c, m, map);
            m = 0;
        }
        else
            Move(s, cmd, map);
    }
    For(n)
    {
        Forj(n)
            Cout map[i][j];
        Enter;
    }
}