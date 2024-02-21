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
#define ulf cout.unsetf(ios::scientific);
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

int GetDec(char ch)
{
	if (among('0', ch, '9'))
		return ch - '0';
	return ch - 'A' + 10;
}

int GetValue(string& str, int idx)
{
	return 16 * GetDec(str[2 * idx]) + GetDec(str[2 * idx + 1]);
}

int main()
{
	FastIO;

	string hex = "0123456789ABCDEF";

	string a, b;
	Cin a >> b;

	int n = a.size() / 2;

	vector<int> result(n + 1);
	result[0] = 32 ^ GetValue(b, 0);
	Foro(n)
		result[i] = result[i - 1] ^ GetValue(a, i - 1) ^ GetValue(b, i);

	for (int x : result)
		Cout hex[x / 16] << hex[x % 16];
}