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

int Find(int n, vector<int>& p)
{
	if (p[n] < 0)
		return n;
	return p[n] = Find(p[n], p);
}

void Union(int a, int b, vector<int>& p)
{
	a = Find(a, p);
	b = Find(b, p);

	if (a == b)
		return;

	p[a] = b;
}

int main()
{
	FastIO;

	int n, m;
	Cin n >> m;

	vector<int> p(n, -1);
	Foro(m)
	{
		int a, b;
		Cin a >> b;

		if (Find(a, p) == Find(b, p))
		{
			Cout i Endl;
			return 0;
		}
		else
			Union(a, b, p);
	}
	Cout 0 Endl;
}