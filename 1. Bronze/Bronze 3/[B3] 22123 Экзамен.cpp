#ifdef ONLINE_JUDGE
#define _128d  __int128
#else
#define _128d long long
#endif

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
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

using namespace std;

template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T>>
{
};

#define MAX_SEC (24 * 60 * 60)

int main()
{
	FastIO;

	int tc;
	scanf("%d", &tc);

	while (tc--)
	{
		int h1, m1, s1, h2, m2, s2, k;
		scanf("%d:%d:%d %d:%d:%d %d", &h1, &m1, &s1, &h2, &m2, &s2, &k);

		int gapSec = (MAX_SEC + 60 * 60 * h2 + 60 * m2 + s2 - (60 * 60 * h1 + 60 * m1 + s1) - 1) % MAX_SEC + 1;
		if (60 * k <= gapSec)
			Cout "Perfect" Endl;
		elif(60 * k <= gapSec + 60 * 60)
			Cout "Test" Endl;
		else
			Cout "Fail" Endl;
	}
}