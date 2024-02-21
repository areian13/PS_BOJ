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

int WaterInPool(vector<vector<int>>& pool)
{
    int n = pool.size();
    int m = pool[0].size();

    int result = 0;
    for (int h = 1; h <= 9; h++)
    {
        vector<vector<bool>> isVisited(n, vector<bool>(m, false));
        For(n)
        {
            Forj(m)
            {
                if (isVisited[i][j] || pool[i][j] >= h)
                    continue;

                isVisited[i][j] = true;

                queue<Pos> Q;
                Q.push({ i,j });

                int cnt = 1;
                bool canInWater = true;

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
                        {
                            canInWater = false;
                            continue;
                        }
                        if (pool[ny][nx] >= h || isVisited[ny][nx])
                            continue;

                        cnt++;
                        isVisited[ny][nx] = true;
                        Q.push({ ny,nx });
                    }
                }
                result += cnt * canInWater;
            }
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    Cin n >> m;

    vector<vector<int>> pool(n, vector<int>(m));
    For(n)
    {
        Forj(m)
        {
            char h;
            Cin h;

            pool[i][j] = (h - '0');
        }
    }

    int result = WaterInPool(pool);
    Cout result Endl;
}