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

struct Lecture {
	int num, start, end;
	bool operator<(Lecture b) const
	{
		if (start == b.start)
			return end < b.end;
		return start < b.start;
	}
	bool operator>(Lecture b) const
	{
		if (start == b.start)
			return end > b.end;
		return start > b.start;
	}
};

int main()
{
	FastIO;

	int n;
	Cin n;

	vector<Lecture> lectures(n);
	For(n)
	{
		int num, start, end;
		Cin num >> start >> end;
		lectures[i] = { num, start, end };
	}
	sort(stoe(lectures));

	heap<Lecture> PQ;
	int result = 0;
	For(n)
	{
		if (!PQ.empty())
		{
			if (PQ.top().start > lectures[i].start)
				result++;
			else
				PQ.pop();
		}
		else
			result++;

		PQ.push({ lectures[i].num, lectures[i].end,lectures[i].start });
	}
	Cout result;
}