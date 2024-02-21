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

int A(int x)
{
	if (x <= 5)
		return 400;
	if (x <= 10)
		return 700;
	if (x <= 20)
		return 1200;
	if (x <= 30)
		return 1700;
	return x * 57;
}
int B(int x)
{
	if (x <= 2)
		return 90 + x * 90;
	if (x <= 5)
		return 100 + x * 85;
	if (x <= 20)
		return 125 + x * 80;
	if (x <= 40)
		return 325 + x * 70;
	return 925 + x * 55;
}
int main()
{
	FastIO;

	int x1, x2;
	Cin x1 >> x2;

	x1 /= 1000;
	x2 /= 1000;

	float result = (min(A(x1), B(x1)) + min(A(x2), B(x2))) / 100.0;

	lf(2);
	Cout result Endl;
}