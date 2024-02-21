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

struct Cand
{
	int idx;
	int score = 0;
	array<int, 4> cnt = { 0, };

	bool operator<(Cand c)
	{
		if (score != c.score)
			return score < c.score;
		if (cnt[3] != c.cnt[3])
			return cnt[3] < c.cnt[3];
		return cnt[2] < c.cnt[2];
	}

	bool operator==(Cand c)
	{
		return score == c.score && cnt == c.cnt;
	}
};

int main()
{
	FastIO;

	array<Cand, 3> cand;
	For(3)
		cand[i].idx = i + 1;

	int n;
	Cin n;

	For(n)
	{
		Forj(3)
		{
			int s;
			Cin s;

			cand[j].score += s;
			cand[j].cnt[s]++;
		}
	}
	sort(stoe(cand));

	Cout (cand[1] == cand[2] ? 0 : cand[2].idx) fspc;
	Cout cand[2].score Endl;
}