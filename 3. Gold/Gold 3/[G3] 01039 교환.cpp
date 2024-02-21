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

struct Info
{
	string num;
	int cnt;

	bool operator==(const Info& c) const
	{
		return num == c.num && cnt == c.cnt;
	}
};

namespace std
{
	template <>
	struct hash<Info>
	{
		size_t operator() (const Info& info) const
		{
			hash<string> hash_func;

			return hash_func(info.num) ^ info.cnt;
		}
	};
}

int main()
{
	FastIO;

	string n;
	int k;
	Cin n >> k;

	unordered_map<Info, bool> isVisited;
	isVisited[{ n,0 }] = true;

	queue<Info> Q;
	Q.push({ n,0 });

	string result = "-1";
	while (!Q.empty())
	{
		string cur = Q.front().num;
		int cnt = Q.front().cnt;
		Q.pop();

		if (cnt == k)
		{
			result = max(result, cur);
			continue;
		}

		for (int i = 0; i < n.size() - 1; i++)
		{
			for (int j = i + 1; j < n.size(); j++)
			{
				if (i == 0 && cur[j] == '0')
					continue;

				string nxt = cur;
				swap(nxt[i], nxt[j]);

				if (isVisited[{ nxt,cnt + 1 }])
					continue;

				isVisited[{ nxt,cnt + 1 }] = true;
				Q.push({ nxt,cnt + 1 });
			}
		}
	}
	Cout result Endl;
}