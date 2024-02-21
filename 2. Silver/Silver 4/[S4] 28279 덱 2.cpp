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

int main()
{
    FastIO;

    int n;
    Cin n;

    deque<int> DQ;
    while (n--)
    {
        int cmd;
        Cin cmd;

        if (cmd == 1)
        {
            int x;
            Cin x;

            DQ.push_front(x);
        }
        elif (cmd == 2)
        {
            int x;
            Cin x;

            DQ.push_back(x);
        }
        elif(cmd == 3)
        {
            if (DQ.empty())
                DQ.push_front(-1);

            Cout DQ.front() Endl;
            DQ.pop_front();
        }
        elif(cmd == 4)
        {
            if (DQ.empty())
                DQ.push_back(-1);

            Cout DQ.back() Endl;
            DQ.pop_back();
        }
        elif(cmd == 5)
            Cout DQ.size() Endl;
        elif(cmd == 6)
            Cout DQ.empty() Endl;
        elif(cmd == 7)
            Cout(DQ.empty() ? -1 : DQ.front()) Endl;
        else
            Cout(DQ.empty() ? -1 : DQ.back()) Endl;
    }
}