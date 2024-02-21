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

bool BS(int num, int start, int end, vector<int>& u)
{
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (u[mid] < num)
			start = mid + 1;
		elif(num < u[mid])
			end = mid - 1;
		else
			return true;
	}
	return false;
}

int main() // O(n^2logn)
{
	FastIO;

	int n;
	Cin n;

	vector<int> u(n);
	For(n)
		Cin u[i];
	sort(stoe(u));

	vector<int> sum((n) * (n + 1) / 2);
	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++, idx++)
			sum[idx] = u[i] + u[j];
	}
	sort(stoe(sum));

	int result = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i; j >= 0; j--)
		{
			if (BS(u[i] - u[j], 0, sum.size() - 1, sum))
			{
				result = u[i];
				goto QUIT_LOOP;
			}
		}
	}
QUIT_LOOP:
	Cout result;
}
// O(n^4)
/*int main()
{
	FastIO;

	int n;
	Cin n;
	
	vector<LLONG> u(n);
	For(n)
		Cin u[i];
	sort(stoe(u));

	LLONG result = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i; j >= 0; j--)
		{
			for (int k = j; k >= 0; k--)
			{
				if (u[i] < u[j] + u[k])
					continue;
				for (int l = k; l >= 0; l--)
				{
					if (u[i] == u[j] + u[k] + u[l])
					{
						result = u[j] + u[k] + u[l];
						goto QUIT_LOOP;
					}
				}
			}
		}
	}
QUIT_LOOP:
	Cout result;
}*/