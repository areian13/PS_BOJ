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

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

bool CanTrapStar(int y, vector<vector<int>>& map)
{
    int n = map.size();
    int m = map[0].size();

    vector<vector<vector<bool>>> isVisited(n, vector<vector<bool>>(m, vector<bool>(4, false)));

    int i = y;

    int x = 0;
    int d = 0;
    while (true)
    {
        isVisited[y][x][d] = true;

        int ny = y + map[y][x] * dy[d];
        int nx = x + map[y][x] * dx[d];
        d = (d + 1) % 4;

        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            return false;
        if (isVisited[ny][nx][d])
            return true;

        y = ny;
        x = nx;
    }
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

    vector<int> result;
    For(n)
    {
        if (CanTrapStar(i, map))
            result.push_back(i + 1);
    }
    Cout result.size() endL result Endl;
}