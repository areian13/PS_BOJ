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

#define MAX 1'000'000

struct Pos
{
    int y, x;
};
struct Info
{
    int num, py, px;
};

array<int, 6> dy = { +1,+2,+1,-1,-2,-1 };
array<int, 6> dx = { +1,+0,-1,-1,+0,+1 };

int main()
{
    FastIO;

    int a, b;
    Cin a >> b;

    int n = 1200;
    vector<vector<Info>> map(n * 2, vector<Info>(n, { 0,-1,-1 }));
    int y = n;
    int x = n / 2;
    int num = 1;
    map[y][x].num = num;
    num++;

    int cnt = 1;
    Pos s, e;
    while (true)
    {
        y += dy[4];
        x += dx[4];

        For(cnt)
        {
            map[y][x].num = num;
            if (num == a)
                s = { y,x };
            if (num == b)
                e = { y,x };
            num++;

            if (num > MAX)
                goto COMPLETE_HONEYCOMB;
            if (i == cnt - 1)
                break;

            y += dy[5];
            x += dx[5];
        }
        
        int dir = 0;
        For(5)
        {
            Forj(cnt)
            {
                y += dy[dir];
                x += dx[dir];

                map[y][x].num = num;
                if (num == a)
                    s = { y,x };
                if (num == b)
                    e = { y,x };
                num++;

                if (num > MAX)
                    goto COMPLETE_HONEYCOMB;
            }
            dir++;
        }
        cnt++;
    }
COMPLETE_HONEYCOMB:

    vector<vector<bool>> isVisited(n * 2, vector<bool>(n, false));
    isVisited[s.y][s.x] = true;

    queue<Pos> Q;
    Q.push(s);

    while (!Q.empty())
    {
        int y = Q.front().y;
        int x = Q.front().x;
        Q.pop();

        For(6)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n * 2 || nx < 0 || nx >= n)
                continue;
            if (isVisited[ny][nx])
                continue;

            map[ny][nx].py = y;
            map[ny][nx].px = x;
            isVisited[ny][nx] = true;
            Q.push({ ny,nx });
        }
    }

    vector<Info> result;
    result.push_back(map[e.y][e.x]);
    while (true)
    {
        int py = result.back().py;
        int px = result.back().px;

        if (py == -1 && px == -1)
            break;

        Info pre = map[py][px];
        result.push_back(pre);
    }
    reverse(stoe(result));

    for (Info& info : result)
        Cout info.num fspc;
}