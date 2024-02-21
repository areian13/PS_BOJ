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

int Indexing(char c, string& hand)
{
    For(3)
    {
        if (hand[i] == c)
            return i;
    }
}

char NextHand(char c, string& hand)
{
    return hand[(Indexing(c, hand) + 1) % 3];
}
char PrevHand(char c, string& hand)
{
    return hand[(Indexing(c, hand) + 2) % 3];
}

#define SIZE 100

int main()
{
    FastIO;

    string result;
    result.resize(SIZE, '2');

    int k;
    Cin k;

    int preK = k;
    string hand = "025";

    For(SIZE)
    {
        result[i] = NextHand(result[i], hand);
        Cout '?' spc result Endl;
        Cout flush;

        Cin k;

        if (k == preK)
            result[i] = NextHand(result[i], hand);
        elif(k < preK)
            result[i] = PrevHand(result[i], hand);
        preK = k + (k <= preK);
    }
    For(SIZE)
        result[i] = NextHand(result[i], hand);

    Cout '!' spc result Endl;
    Cout flush;
}