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

array<bool, 500'001> sosu;
array<int, 10'001> nofPrice = { 0, };
array<LLONG, 500'001> cnt = { 1,0, };

int main()
{
	FastIO;

	fill(stoe(sosu), true);
	sosu[0] = sosu[1] = false;
	for (int i = 2; i <= 500'000; i++)
	{
		if (!sosu[i])
			continue;
		for (int j = 2; i * j <= 500'000; j++)
			sosu[i * j] = false;
	}
	
	int n;
	Cin n;

	For(n)
	{
		int a;
		Cin a;
		nofPrice[a]++;
	}

	for (int i = 10'000; i > 0; i--)
	{
		if (nofPrice[i] == 0)
			continue;
		for (int j = 500'000; j > 0; j--)
		{
			for (int k = 1; k <= nofPrice[i]; k++)
			{
				if (j < i * k)
					break;
				cnt[j] += cnt[j - i * k];
			}
		}
	}

	LLONG result = 0;
	for (int i = 0; i < 500'001; i++)
	{
		if (!sosu[i])
			continue;
		result += cnt[i];
	}
	Cout result * (nofPrice[0] + 1);
}