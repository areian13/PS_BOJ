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
        cout << value << ' ';
}

template <typename T, size_t N>
ostream& operator<<(ostream& os, array<T, N>& vec)
{
    for (T& value : vec)
        cout << value << ' ';
}

struct Pos
{
    int y, x;
};

array<int, 8> dy = { -1,-1,-1,0,1,1,1,0 };
array<int, 8> dx = { -1,0,1,1,1,0,-1,-1 };
string dir = "EWQAZXCD";

int main()
{
    FastIO;

    int n;
    Cin n;

    vector<vector<int>> map(50, vector<int>(50, -1));
    For(n)
    {
        int x, y;
        Cin x >> y;

        map[y + 15][x + 15] = i;
    }

    vector<vector<string>> order(50, vector<string>(50, "."));
    order[15][15] = "";

    queue<Pos> Q;
    Q.push({ 15,15 });

    vector<string> result(n, "");
    while (!Q.empty())
    {
        int l = Q.size();
        bool find04 = false;
        Forj(l)
        {
            int y = Q.front().y;
            int x = Q.front().x;
            Q.pop();

            For(8)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny > 49 || nx < 0 || nx > 49)
                    continue;
                if (order[ny][nx] != ".")
                    continue;

                if (map[ny][nx] != -1)
                {
                    if (!find04)
                    {
                        order[ny][nx] = order[y][x] + dir[i];
                        Q.push({ ny,nx });

                        result[map[ny][nx]] = order[ny][nx];
                        reverse(stoe(result[map[ny][nx]]));
                        find04 = true;
                    }
                    continue;
                }
                order[ny][nx] = order[y][x] + dir[i];
                Q.push({ ny,nx });
            }
        }
    }
    For(n)
        Cout result[i] Endl;
}
