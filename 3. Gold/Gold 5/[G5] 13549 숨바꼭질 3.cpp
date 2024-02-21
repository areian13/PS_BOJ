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

int Moving(int x, int i)
{
	if (i == 0) return x * 2;
	if(i == 1) return x - 1;
	return x + 1;
}

int main()
{
	FastIO;

	int n, k;
	Cin n >> k;

	vector<int> result(100'002, -1);
	result[n] = 0;

	deque<int> D;
	D.push_back(n);

	while (!D.empty())
	{
		int cur = D.front();
		D.pop_front();

		For(3)
		{
			int nxt = Moving(cur, i);
			if (nxt < 0 || nxt > 100'000)
				continue;
			if (result[nxt] >= 0)
				continue;

			result[nxt] = result[cur] + (i != 0);
			D.push_back(nxt);

			if (nxt == k)
			{
				while (!D.empty())
					D.pop_front();
			}
		}
	}
	Cout result[k] Endl;
}
