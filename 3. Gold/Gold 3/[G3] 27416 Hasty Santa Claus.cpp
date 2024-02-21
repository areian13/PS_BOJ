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

struct Calendar
{
	int idx;

	int start;
	int end;

	int visitDate;
};
struct Visit
{
	int cnt;
	int k;
};

bool SortDate(Calendar& a, Calendar& b)
{
	if (a.end != b.end)
		return a.end < b.end;
	return a.start < b.start;
}
bool SortIndex(Calendar& a, Calendar& b)
{
	return a.idx < b.idx;
}

int main()
{
	FastIO;

	int n, k;
	Cin n >> k;

	vector<Calendar> calendar(n);
	array<Visit, 32> canVisit;
	fill(stoe(canVisit), Visit{ 0, k });
	For(n)
	{
		int a, b;
		Cin a >> b;

		calendar[i] = { i,a,b };
		for (int j = a; j <= b; j++)
			canVisit[j].cnt++;
	}
	sort(stoe(calendar), SortDate);

	For(n)
	{
		int visitDate = calendar[i].start;
		while (canVisit[visitDate].cnt == 0 || canVisit[visitDate].k == 0)
			visitDate++;

		calendar[i].visitDate = visitDate;
		canVisit[visitDate].cnt--;
		canVisit[visitDate].k--;
	}
	sort(stoe(calendar), SortIndex);
	For(n)
		Cout calendar[i].visitDate Endl;
}
