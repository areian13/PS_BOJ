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

int CountBlack(int n, vector<bool>& isUsedG, vector<bool>& isUsedT, string& guess, string& target)
{
    int result = 0;
    For(n)
    {
        if (guess[i] == target[i])
        {
            result++;
            isUsedG[i] = true;
            isUsedT[i] = true;
        }
    }
    return result;
}
int CountGrey(int n, vector<bool>& isUsedG, vector<bool>& isUsedT, string& guess, string& target)
{
    int result = 0;
    For(n)
    {
        if (isUsedG[i])
            continue;

        if (0 < i && guess[i] == target[i - 1] && !isUsedT[i - 1])
        {
            result++;
            isUsedG[i] = true;
            isUsedT[i - 1] = true;
        }
        elif(i < n - 1 && guess[i] == target[i + 1] && !isUsedT[i + 1])
        {
            result++;
            isUsedG[i] = true;
            isUsedT[i + 1] = true;
        }
    }
    return result;
}
int CountWhite(int n, vector<bool>& isUsedG, vector<bool>& isUsedT, string& guess, string& target)
{
    int result = 0;
    For(n)
    {
        if (isUsedG[i])
            continue;

        Forj(n)
        {
            if (guess[i] == target[j] && !isUsedT[j])
            {
                result++;
                isUsedG[i] = true;
                isUsedT[j] = true;
            }
        }
    }
    return result;
}

int main()
{
    FastIO;

    while (true)
    {
        string target;
        Cin target;
        if (target == "#")
            break;

        string guess;
        Cin guess;

        int n = target.size();
        vector<bool> isUsedG(n, false);
        vector<bool> isUsedT(n, false);

        int b = CountBlack(n, isUsedG, isUsedT, guess, target);
        int g = CountGrey(n, isUsedG, isUsedT, guess, target);
        int w = CountWhite(n, isUsedG, isUsedT, guess, target);
        
        printf("%s: %d black, %d grey, %d white\n", guess.c_str(), b, g, w);
    }
}