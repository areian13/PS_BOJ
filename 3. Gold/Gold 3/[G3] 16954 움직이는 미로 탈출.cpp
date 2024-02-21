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
    int y, x, z;
};

array<int, 9> dy = { -1,-1,-1,0,1,1,1,0,0 };
array<int, 9> dx = { -1,0,1,1,1,0,-1,-1,0 };

int main()
{
    FastIO;

    int n = 8;

    vector<vector<vector<char>>> map(n, vector<vector<char>>(n, vector<char>(n, '.')));
    For(n)
    {
        Forj(n)
        {
            Cin map[i][j][0];

            if (map[i][j][0] != '#')
                continue;

            for (int k = 0; i + k < n; k++)
                map[i + k][j][k] = '#';
        }
    }
    
    vector<vector<vector<bool>>> isVisited(n, vector<vector<bool>>(n, vector<bool>(n, false)));
    isVisited[n - 1][0][0] = true;

    queue<Pos> Q;
    Q.push({ n - 1,0,0 });

    while (!Q.empty())
    {
        int y = Q.front().y;
        int x = Q.front().x;
        int z = Q.front().z;
        Q.pop();

        For(9)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nz = z + (z < 7);

            if (ny < 0 || ny >= n || nx < 0 || nx >= n || nz >= n)
                continue;
            if (map[ny][nx][z] == '#' || map[ny][nx][nz] == '#' || isVisited[ny][nx][nz])
                continue;

            isVisited[ny][nx][nz] = true;
            Q.push({ ny,nx,nz });
        }
    }

    bool result = isVisited[0][n - 1][n - 1];
    Cout result Endl;
}