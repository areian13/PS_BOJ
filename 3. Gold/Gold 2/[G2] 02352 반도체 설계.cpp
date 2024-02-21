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
#include <random>

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

struct Dic
{
	int value, idx;

	bool operator<(Dic c)
	{
		if (value == c.value)
			return idx > c.idx;
		return value < c.value;
	}
};

int LIS(int start, int end, int idx, int left, int right, vector<int>& arr)
{
	if (end < left || right < start)
		return 0;
	if (start <= left && right <= end)
		return arr[idx];
	int mid = (left + right) / 2;

	return max(LIS(start, end, 2 * idx, left, mid, arr),
		LIS(start, end, 2 * idx + 1, mid + 1, right, arr));
}

void Update(int idx, int value, vector<int>& arr)
{
	arr[idx] = value;
	while (idx > 1)
	{
		idx /= 2;
		arr[idx] = max(arr[2 * idx], arr[2 * idx + 1]);
	}
}

int main()
{
	FastIO;

	int n;
	Cin n;

	vector<Dic> a(n);
	For(n)
	{
		Cin a[i].value;
		a[i].value--;
		a[i].idx = i;
	}
	sort(stoe(a));

	int r = log2(2 * n - 1);
	int size = pow(2, r);

	vector<int> arr(2 * size, 0);
	For(n)
		Update(a[i].idx + size, LIS(0, a[i].idx, 1, 0, size - 1, arr) + 1, arr);
	Cout arr[1] Endl;
}