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

#define MAX 200

int main()
{
	FastIO;

	array<int, 3> bottle;
	For(3)
		Cin bottle[i];

	vector<vector<vector<bool>>> isVisited(bottle[0] + 1, vector<vector<bool>>(bottle[1] + 1, vector<bool>(bottle[2] + 1, false)));
	isVisited[0][0][bottle[2]] = true;

	vector<bool> result(bottle[2] + 1, false);
	result[bottle[2]] = true;

	queue<array<int, 3>> Q;
	Q.push({ 0,0,bottle[2]});

	while (!Q.empty())
	{
		array<int, 3> cur = Q.front();
		Q.pop();

		For(3)
		{
			if (cur[i] == 0)
				continue;
			Forj(3)
			{
				if (i == j)
					continue;

				array<int, 3> nxt = cur;
				int spent = min(nxt[i], bottle[j] - nxt[j]);
				nxt[i] -= spent;
				nxt[j] += spent;

				if (isVisited[nxt[0]][nxt[1]][nxt[2]])
					continue;

				isVisited[nxt[0]][nxt[1]][nxt[2]] = true;
				result[nxt[2]] = result[nxt[2]] || (nxt[0] == 0);
				Q.push(nxt);
			}
		}
	}
	for (int i = 0; i <= bottle[2]; i++)
	{
		if (result[i])
			Cout i fspc;
	}
}