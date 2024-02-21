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

vector<vector<int>> edge;
vector<int> nthDFS, nthSCC;
vector<bool> isFinished;

stack<int> S;

int cntDFS = 0, cntSCC = 0;

int DFS(int cur)
{
	nthDFS[cur] = ++cntDFS;
	S.push(cur);

	int result = nthDFS[cur];
	for (int nxt : edge[cur])
	{
		if (nthDFS[nxt] == 0)
			result = min(result, DFS(nxt));
		elif(!isFinished[nxt])
			result = min(result, nthDFS[nxt]);
	}

	if (result == nthDFS[cur])
	{
		while (true)
		{
			int top = S.top();
			S.pop();

			isFinished[top] = true;
			nthSCC[top] = cntSCC;
			if (top == cur)
				break;
		}
		cntSCC++;
	}
	return result;
}

int main()
{
	FastIO;

	int n, m;
	Cin n >> m;

	edge.resize(2 * n);
	nthDFS.resize(2 * n);
	nthSCC.resize(2 * n);
	isFinished.resize(2 * n);

	For(m)
	{
		int l, r;
		Cin l >> r;

		l = (l < 0 ? -(l + 1) * 2 : l * 2 - 1);
		r = (r < 0 ? -(r + 1) * 2 : r * 2 - 1);

		edge[l % 2 == 0 ? l + 1 : l - 1].push_back(r);
		edge[r % 2 == 0 ? r + 1 : r - 1].push_back(l);
	}

	For(2 * n)
	{
		if (nthDFS[i] == 0)
			DFS(i);
	}

	bool result = true;
	For(n)
		result &= (nthSCC[i * 2] != nthSCC[i * 2 + 1]);
	Cout result Endl;
}