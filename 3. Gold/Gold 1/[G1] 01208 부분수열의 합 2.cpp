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

int n, s;
vector<int> arr;
unordered_map<int, int> UMP;
LLONG result = 0;

void LeftSearch(int idx, int sum)
{
	if (idx == n / 2)
	{
		UMP[sum]++;
		return;
	}
	LeftSearch(idx + 1, sum + arr[idx]);
	LeftSearch(idx + 1, sum);
}

void RightSearch(int idx, int sum)
{
	if (idx == n)
	{
		result += UMP[s - sum];
		return;
	}
	RightSearch(idx + 1, sum + arr[idx]);
	RightSearch(idx + 1, sum);
}
int main()
{
	FastIO;

	Cin n >> s;
	
	arr.resize(n);
	For(n)
		Cin arr[i];
	sort(stoe(arr));

	LeftSearch(0, 0);
	RightSearch(n / 2, 0);

	if (s == 0)
		result--;
	Cout result;
}