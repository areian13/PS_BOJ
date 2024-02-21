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

LLONG Binary(int i, int j, int n, int l, vector<vector<LLONG>>& dp)
{
	if (i == n || j == l)
		return dp[i][j] = 1;
	if (dp[i][j])
		return dp[i][j];
	return dp[i][j] = Binary(i + 1, j, n, l, dp) + Binary(i + 1, j + 1, n, l, dp);
}
int main()
{
	int n, l;
	LLONG k;
	Cin n >> l >> k;

	vector<vector<LLONG>> dp(n + 1, vector<LLONG>(l + 1, 0));
	for (int i = 1, j = 0; i <= n; i++)
	{
		LLONG ithCase = Binary(i, j, n, l, dp);
		bool isValid = ithCase < k;

		k -= ithCase * isValid;
		j += isValid;

		Cout isValid;
	}
}
//브루트포스
/*int CountOne(int n)
{
	int result = 0;
	while (n)
	{
		result += n % 2;
		n /= 2;
	}
	return result;
}
string MakeBin(int n)
{
	string result;
	while (n)
	{
		result += n % 2 + '0';
		n /= 2;
	}
	reverse(stoe(result));
	return result;
}
int main()
{
	FastIO;

	int n, l, k;
	Cin n >> l >> k;

	int num = pow(2, n) - 1;

	int cnt = 0;
	for (int i = 0; i <= num; i++)
	{
		if (CountOne(i) <= l)
			cnt++;
		if (cnt == k)
		{
			Cout MakeBin(i) Endl;
			break;
		}
	}
}*/