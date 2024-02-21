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
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <limits.h>
#include <float.h>
#include <string.h>
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

struct Lecture
{
    int c;
    string g;
};

double Score(string& g)
{
    if (g == "F")
        return 0.0;
    return (4 - (g[0] - 'A') + (g[1] == '+' ? 0.5 : 0.0));
}

double AvgScore(vector<Lecture>& lectures)
{
    double scoreSum = 0;
    int cSum = 0;

    for (Lecture& lecture : lectures)
    {
        scoreSum += lecture.c * Score(lecture.g);
        cSum += lecture.c;
    }
    return (double)(int)(scoreSum * 100 / cSum) / 100;
}

int main()
{
    FastIO;

    string grades[] = { "F","D0","D+","C0","C+","B0","B+","A0","A+" };

    int n;
    double x;
    Cin n >> x;

    vector<Lecture> lectures(n);
    For(n - 1)
        Cin lectures[i].c >> lectures[i].g;

    int c;
    Cin c;
    lectures[n - 1].c = c;

    string result = "impossible";
    for (string grade : grades)
    {
        lectures[n - 1].g = grade;
        double score = AvgScore(lectures);
        if (score > x)
        {
            result = grade;
            break;
        }
    }
    Cout result Endl;
}