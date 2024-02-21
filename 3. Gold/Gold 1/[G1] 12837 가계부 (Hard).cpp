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

LLONG SegTree(int start, int end, int idx, int left, int right, vector<LLONG>& arr)
{
	if (end < left || right < start)
		return 0;
	if (start <= left && right <= end)
		return arr[idx];

	int mid = (left + right) / 2;

	return SegTree(start, end, 2 * idx, left, mid, arr) + SegTree(start, end, 2 * idx + 1, mid + 1, right, arr);
}

int main()
{
	FastIO;

	int n, m;
	Cin n >> m;

	int r = log2(2 * n - 1);
	int size = pow(2, r);

	vector<LLONG> arr(2 * size, 0);
	For(m)
	{
		int type, p, q;
		Cin type >> p >> q;

		if (type == 1)
		{
			p += size - 1;
			arr[p] += q;

			while (p > 1)
			{
				p /= 2;
				arr[p] = arr[p * 2] + arr[p * 2 + 1];
			}
		}
		elif(type == 2)
			Cout SegTree(p - 1, q - 1, 1, 0, size - 1, arr) Endl;
	}
}