#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <time.h>
#include <ctime>
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
#include <malloc.h>
#include <typeinfo>

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
#define StoE(container) container.begin(), container.end()
#define lf(d) Cout fixed; cout.precision(d);
#define ulf cout.unsetf(ios::scientific);
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define PI 3.14159265359


typedef long long LLONG;
typedef unsigned int UINT;
using namespace std;


template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T>>
{
};

int BS(LLONG x, LLONG y)
{
	int z = y * 100 / x;
	if (z >= 99)
		return -1;

	int start = 0, end = 1'000'000'000;
	int result = end;

	while (start <= end)
	{
		int mid = (start + end) / 2;
		int tempZ = (y + mid) * 100 / (x + mid);
		if (z >= tempZ)
			start = mid + 1;
		else
		{
			result = min(result, mid);
			end = mid - 1;
		}
	}
	return result;
}

int main(void)
{
	FastIO;

	LLONG x, y;
	Cin x >> y;

	int result = BS(x, y);
	Cout result;
}