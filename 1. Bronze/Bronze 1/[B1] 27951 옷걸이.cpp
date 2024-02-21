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

int main()
{
	FastIO;

	int n;
	Cin n;

	vector<int> h(n);
	array<int, 3>  cnt = { 0,0,0 };
	For(n)
	{
		Cin h[i];
		cnt[h[i] - 1]++;
	}

	int u, d;
	Cin u >> d;

	if (cnt[0] + cnt[2] < u || cnt[1] + cnt[2] < d)
	{
		Cout "NO" Endl;
		return 0;
	}

	Cout "YES" Endl;
	string result;
	result.resize(n);
	For(n)
	{
		switch (h[i])
		{
		case 1:
			u--;
			cnt[0]--;
			result[i] = 'U';
			break;

		case 2:
			d--;
			cnt[1]--;
			result[i] = 'D';
			break;

		case 3:
			if (cnt[0] + cnt[2] - u <= cnt[1] + cnt[2] - d)
			{
				u--;
				cnt[2]--;
				result[i] = 'U';
			}
			else
			{
				d--;
				cnt[2]--;
				result[i] = 'D';
			}
			break;
		}
	}
	Cout result Endl;
}