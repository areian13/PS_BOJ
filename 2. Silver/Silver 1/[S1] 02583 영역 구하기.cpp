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

// 2¹ø
int DFS(int y, int x, vector<vector<bool>>& isVisited, vector<vector<int>>& map)
{
    int m = map.size();
    int n = map[0].size();

    isVisited[y][x] = true;
    int area = 1;

    For(4)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= m || nx < 0 || nx >= n)
            continue;
        if (map[ny][nx] == 1 || isVisited[ny][nx])
            continue;

        area += DFS(ny, nx, isVisited, map);
    }
    return area;
}

int main()
{
    FastIO;

    int m, n, k;
    Cin m >> n >> k;

    vector<vector<int>> map(m, vector<int>(n, false));
    For(k)
    {
        int x1, y1, x2, y2;
        Cin x1 >> y1 >> x2 >> y2;

        for (int i = m - y1 - 1; i >= m - y2; i--)
        {
            for (int j = x1; j < x2; j++)
                map[i][j] = 1;
        }
    }

    vector<int> result;
    vector<vector<bool>> isVisited(m, vector<bool>(n, false));
    For(m)
    {
        Forj(n)
        {
            if (map[i][j] == 1 || isVisited[i][j])
                continue;

            int area = DFS(i, j, isVisited, map);
            result.push_back(area);
        }
    }
    sort(stoe(result));

    Cout result.size() endL result Endl;
}