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

vector<vector<int>> edge;
vector<int> nthDFS, nthSCC;
vector<bool> isFinished;

stack<int> S;

int cntDFS = 0, cntSCC = 0;

void Init()
{
	edge.clear();
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

	int tc;
	Cin tc;

	while (tc--)
	{
		Init();

		int n, m;
		Cin n >> m;

		edge.resize(n + 1);
		For(m)
		{
			int x, y;
			Cin x >> y;

			edge[x].push_back(y);
		}

		nthDFS.resize(n + 1, 0);
		nthSCC.resize(n + 1, 0);
		isFinished.resize(n + 1, false);


		Foro(n)
		{
			if (nthDFS[i] == 0)
				DFS(i);
		}

		vector<int> indegree(cntSCC, 0);
		Foro(n)
		{
			for (int nxt : edge[i])
			{
				if (nthSCC[i] != nthSCC[nxt])
					indegree[nthSCC[nxt]]++;
			}
		}

		int result = 0;
		For(cntSCC)
			result += (indegree[i] == 0);
		Cout result Endl;
	}
}