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

LLONG Result(int start, int end, vector<LLONG>& arr, vector<LLONG>& preSum)
{
	if (start == end)
		return arr[start] * arr[start];
	int mid = (start + end) / 2;
	LLONG result = max(Result(start, mid, arr, preSum), Result(mid + 1, end, arr, preSum));

	int left = mid;
	int right = mid + 1;
	LLONG minValue = min(arr[left], arr[right]);
	result = max(result, (preSum[right] - preSum[left - 1]) * minValue);

	while (start < left || right < end)
	{
		if (right < end && (start == left || arr[left - 1] < arr[right + 1]))
		{
			right++;
			minValue = min(minValue, arr[right]);
		}
		else
		{
			left--;
			minValue = min(minValue, arr[left]);
		}
		result = max(result, (preSum[right] - preSum[left - 1]) * minValue);
	}
	return result;
}

int main()
{
	FastIO;

	int n;
	Cin n;

	vector<LLONG> arr(n + 1);
	vector<LLONG> preSum(n + 1, 0);
	Foro(n)
	{
		Cin arr[i];
		preSum[i] = preSum[i - 1] + arr[i];
	}

	Cout Result(1, n, arr, preSum);
}