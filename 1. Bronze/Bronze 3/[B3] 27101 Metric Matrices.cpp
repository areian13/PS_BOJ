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

int CheckMatrix(vector<vector<int>>& matrix)
{
    int n = matrix.size();

    int result = 5;
    For(n)
    {
        Forj(n)
        {
            if (i == j && matrix[i][j] != 0)
                result = min(result, 1);
            if (i != j && matrix[i][j] <= 0)
                result = min(result, 2);
            if (matrix[i][j] != matrix[j][i])
                result = min(result, 3);
            for (int k = 0; k < n; k++)
            {
                if (matrix[i][j] + matrix[j][k] < matrix[i][k])
                    result = min(result, 4);
            }
        }
    }
    result = (result == 5 ? 0 : result);
    return result;
}

int main()
{
    FastIO;

    int n;
    Cin n;

    vector<vector<int>> matrix(n, vector<int>(n));
    For(n)
    {
        Forj(n)
            Cin matrix[i][j];
    }

    int result = CheckMatrix(matrix);
    Cout result Endl;
}