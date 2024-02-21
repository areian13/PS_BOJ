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

int Value(int a, int c, array<int, 3>& rgb)
{
	return a * (rgb[0] * rgb[0] + rgb[1] * rgb[1] + rgb[2] * rgb[2]) + c * min({ rgb[0],rgb[1],rgb[2] });
}

int main()
{
	FastIO;

	array<string, 3> RGB = { "RED","GREEN","BLUE" };

	int tc;
	Cin tc;

	while (tc--)
	{
		int a, c;
		array<int, 3> rgb;
		Cin a >> c;
		For(3)
			Cin rgb[i];

		int maxValue = Value(a, c, rgb);
		string result;
		For(3)
		{
			rgb[i]++;
			int value = Value(a, c, rgb);
			if (value > maxValue)
			{
				maxValue = value;
				result = RGB[i];
			}
			rgb[i]--;
		}
		Cout result Endl;
	}
}