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

LLONG Add(LLONG a, LLONG b, LLONG pre)
{
	return (a + b) - pre;
}

LLONG Sub(LLONG a, LLONG b, LLONG pre)
{
	return (a - b) * pre;
}
LLONG Mul(LLONG a, LLONG b)
{
	return pow(a * b, 2);
}
LLONG Div(LLONG a)
{
	return (a + 1) / 2;
}

int main()
{
	FastIO;

	int n;
	Cin n;

	LLONG pre = 1;
	while (n--)
	{
		LLONG a, b;
		char op;
		Cin a >> op >> b;

		switch (op)
		{
		case '+':
			pre = Add(a, b, pre);
			break;
		case '-':
			pre = Sub(a, b, pre);
			break;
		case '*':
			pre = Mul(a, b);
			break;
		case '/':
			pre = Div(a);
			break;
		}
		Cout pre Endl;
	}
}