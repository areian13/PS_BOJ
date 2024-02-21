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
vector<int> nthDFS, nthSCC;
vector<bool> isFinished;

stack<int> S;

int cntDFS = 0, cntSCC = 0;

void Init()
{
	edge.clear();
	SCC.clear();
	nthDFS.clear();
	nthSCC.clear();
	isFinished.clear();

	cntDFS = 0;
	cntSCC = 0;

	while (!S.empty())
		S.pop();
}

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
		vector<int> curSCC;
		while (true)
		{
			int top = S.top();
			S.pop();

			curSCC.push_back(top);
			isFinished[top] = true;
			nthSCC[top] = cntSCC;
			if (top == cur)
				break;
		}
		cntSCC++;
		SCC.push_back(curSCC);
	}
	return result;
}

int main()
{
	FastIO;

	int tc;
	Cin tc;

	while (tc--)
	{
		Init();

		int n, m;
		Cin n >> m;

		edge.resize(n);
		For(m)
		{
			int x, y;
			Cin x >> y;

			edge[x].push_back(y);
		}

		nthDFS.resize(n, 0);
		nthSCC.resize(n, 0);
		isFinished.resize(n, false);

		For(n)
		{
			if (nthDFS[i] == 0)
				DFS(i);
		}

		vector<int> indegree(cntSCC, 0);
		For(n)
		{
			for (int nxt : edge[i])
			{
				if (nthSCC[i] != nthSCC[nxt])
					indegree[nthSCC[nxt]]++;
			}
		}

		vector<int> result;
		int cntIndegreeZeroSCC = 0;
		For(cntSCC)
		{
			if (indegree[i] == 0)
			{
				cntIndegreeZeroSCC++;
				if (cntIndegreeZeroSCC >= 2)
					break;

				result = SCC[i];
			}
		}
		sort(stoe(result));

		if (cntIndegreeZeroSCC == 1)
		{
			for (int node : result)
				Cout node Endl;
		}
		else
			Cout "Confused" Endl;
		Enter;
	}
}