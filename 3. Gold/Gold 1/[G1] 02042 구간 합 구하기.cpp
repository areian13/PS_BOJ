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
#define between(small, middle, big) small < middle && middle < big
#define among(small, middle, big) small <= middle && middle <= big
#define stoe(container) container.begin(), container.end()
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI 3.14159265359

typedef long long LLONG;
typedef unsigned int UINT;

using namespace std;

template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T>>
{
};

LLONG Sum(LLONG l, LLONG r, LLONG nodeNum, LLONG nodeL, LLONG nodeR, vector<LLONG>& arr)
{
	if (r < nodeL || nodeR < l)
		return 0;
	if (l <= nodeL && nodeR <= r)
		return arr[nodeNum];
	LLONG mid = (nodeL + nodeR) / 2;
	return Sum(l, r, 2 * nodeNum, nodeL, mid, arr) + Sum(l, r, 2 * nodeNum + 1, mid + 1, nodeR, arr);
}

int main()
{
	FastIO;

	int n, m, k;
	Cin n >> m >> k;
	int r = log2(2 * n - 1);
	int size = pow(2, r);

	vector<LLONG> arr(2 * size);
	For(n)
		Cin arr[size + i];

	for (int i = size - 1; i > 0; i--)
		arr[i] = arr[i * 2] + arr[i * 2 + 1];

	For(m + k)
	{
		int a;
		LLONG b, c;
		Cin a >> b >> c;
		if (a == 1)
		{
			b += size - 1;
			arr[b] = c;
			while (b > 1)
			{
				b /= 2;
				arr[b] = arr[b * 2] + arr[b * 2 + 1];

			}
		}
		elif(a == 2)
			Cout Sum(b - 1, c - 1, 1, 0, size - 1, arr) Endl;
	}
}