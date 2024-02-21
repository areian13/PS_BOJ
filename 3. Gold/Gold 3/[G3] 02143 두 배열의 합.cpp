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

unordered_map<int, int> UM;

int Sum(int i, int j, vector<int>& preSum)
{
	return preSum[j] - preSum[i - 1];
}

int main()
{
	FastIO;

	int t;
	Cin t;

	int n;
	Cin n;

	vector<int> aPre(n + 1, 0);
	For(n)
	{
		int a;
		Cin a;
		aPre[i + 1] = aPre[i] + a;
	}

	int m;
	Cin m;

	vector<int> bPre(m + 1, 0);
	For(m)
	{
		int b;
		Cin b;
		bPre[i + 1] = bPre[i] + b;
	}

	vector<int> bSum(m * (m + 1) / 2);
	for (int i = 1, idx = 0; i <= m; i++)
	{
		for (int j = i; j <= m; j++, idx++)
		{
			bSum[idx] = Sum(i, j, bPre);
			UM[bSum[idx]]++;
		}
	}
	sort(stoe(bSum));

	LLONG result = 0;
	for (int i = 1, idx = 0; i <= n; i++)
	{
		for (int j = i; j <= n; j++, idx++)
		{
			int lValue = t - Sum(i, j, aPre);

			int start = 0;
			int end = bSum.size() - 1;

			while (start <= end)
			{
				int mid = (start + end) / 2;

				if (lValue > bSum[mid])
					start = mid + 1;
				elif(lValue < bSum[mid])
					end = mid - 1;
				else
				{
					result += UM[bSum[mid]];
					break;
				}
			}
		}
	}
	Cout result;
}