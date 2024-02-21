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

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,1,0,-1 };

int main()
{
    FastIO;

    int n, m;
    Cin n >> m;

    vector<vector<char>> map(n, vector<char>(m));
    For(n)
    {
        Forj(m)
            Cin map[i][j];
    }

    int result = 0;
    For(n)
    {
        Forj(m)
        {
            if (map[i][j] == 'W')
                continue;

            vector<vector<int>> dist(n, vector<int>(m, -1));
            dist[i][j] = 0;

            queue<Pos> Q;
            Q.push({ i,j });

            while (!Q.empty())
            {
                int y = Q.front().y;
                int x = Q.front().x;
                Q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int ny = y + dy[k];
                    int nx = x + dx[k];

                    if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                        continue;
                    if (dist[ny][nx] != -1 || map[ny][nx] == 'W')
                        continue;

                    dist[ny][nx] = dist[y][x] + 1;
                    Q.push({ ny,nx });

                    result = max(result, dist[ny][nx]);
                }
            }
        }
    }
    Cout result Endl;
}