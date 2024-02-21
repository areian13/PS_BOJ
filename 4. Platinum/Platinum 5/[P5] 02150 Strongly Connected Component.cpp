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

vector<vector<int>> edge, SCC;
vector<int> nthDFS;
vector<bool> isFinished;

stack<int> S;

int cnt = 0;

int DFS(int cur)
{
	nthDFS[cur] = ++cnt;
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
		vector<int> curSCC;

		while (true)
		{
			int top = S.top();
			S.pop();

			curSCC.push_back(top);
			isFinished[top] = true;

			if (top == cur)
				break;
		}

		sort(stoe(curSCC));
		SCC.push_back(curSCC);
	}

	return result;
}

int main()
{
	FastIO;

	int v, e;
	Cin v >> e;
	
	edge.resize(v + 1);
	For(e)
	{
		int a, b;
		Cin a >> b;

		edge[a].push_back(b);
	}

	nthDFS.resize(v + 1, 0);
	isFinished.resize(v + 1, false);

	Foro(v)
	{
		if (nthDFS[i] == 0)
			DFS(i);
	}
	sort(stoe(SCC));

	Cout SCC.size() Endl;
	For(SCC.size())
	{
		for (int node : SCC[i])
			Cout node fspc;
		Cout -1 Endl;
	}
}