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

    int n, k;
    Cin n >> k;

    vector<int> order(k);
    vector<vector<int>> orderSeqs(k + 1);
    For(k)
    {
        Cin order[i];
        orderSeqs[order[i]].push_back(i);
    }

    Foro(k)
        reverse(stoe(orderSeqs[i]));

    int result = 0;
    vector<bool> isPlugged(k + 1, false);
    vector<int> plug;
    For(k)
    {
        if (isPlugged[order[i]])
        {
            orderSeqs[order[i]].pop_back();
            continue;
        }

        if (plug.size() < n)
        {
            isPlugged[order[i]] = true;
            plug.push_back(order[i]);
            orderSeqs[order[i]].pop_back();
            continue;
        }

        result++;

        int outPlug = -1;
        int outPlugIdx = -1;
        int lastPlug = -1;
        Forj(plug.size())
        {
            if (orderSeqs[plug[j]].empty())
            {
                outPlug = plug[j];
                outPlugIdx = j;
                break;
            }
            elif(orderSeqs[plug[j]].back() > lastPlug)
            {
                outPlug = plug[j];
                outPlugIdx = j;
                lastPlug = orderSeqs[plug[j]].back();
            }
        }
            
        isPlugged[outPlug] = false;
        plug.erase(plug.begin() + outPlugIdx);

        isPlugged[order[i]] = true;
        plug.push_back(order[i]);
        orderSeqs[order[i]].pop_back();
    }
    Cout result Endl;
}