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

#define Endl << "\n"
#define endL << "\n" <<
#define Cout cout <<
#define	COUT cout << "OUT: " <<
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

int main()
{
	FastIO;

	char bigNum[10][5][5] = {
		"0000",
		"0  0",
		"0  0",
		"0  0",
		"0000",

		"   1",
		"   1",
		"   1",
		"   1",
		"   1",

		"2222",
		"   2",
		"2222",
		"2",
		"2222",

		"3333",
		"   3",
		"3333",
		"   3",
		"3333",

		"4  4",
		"4  4",
		"4444",
		"   4",
		"   4",

		"5555",
		"5",
		"5555",
		"   5",
		"5555",

		"6666",
		"6",
		"6666",
		"6  6",
		"6666",

		"7777",
		"   7",
		"   7",
		"   7",
		"   7",

		"8888",
		"8  8",
		"8888",
		"8  8",
		"8888",

		"9999",
		"9  9",
		"9999",
		"   9",
		"   9",
	};

	string cmd;
	Cin cmd;

	for (auto chr : cmd)
	{
		For(5)
			Cout bigNum[chr - '0'][i] Endl;
		Enter;
	}
}